#include "view.hpp"
#include <visual_object/visual/visual.hpp>
#include <window/mouse_const.hpp>
#include <lib/macro/warn.hpp>
#include <action/impl/cmd_new_interface_bar.hpp>

namespace vp {

wxBEGIN_EVENT_TABLE(view, wxWindow)
    EVT_MOUSE_EVENTS(view::on_mouse_event)
    EVT_KEY_DOWN(view::on_key_down)
    EVT_KEY_UP(view::on_key_up)
    EVT_CHAR(view::on_char)
    EVT_COMMAND(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, view::on_command)
    EVT_MENU(wxID_ANY, view::on_menu)
    EVT_PAINT(view::on_draw)
wxEND_EVENT_TABLE();

static ptr<visual> get_mouse_processor
    (ptr<visual> prior, ptr<visual> _default,
            const list<ptr<visual>>&, const wxPoint& pos);

view::view(ptr<document> doc, wxWindow* parent) :
    wxWindow(parent, wxID_ANY), visual(doc) {
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    m_doc = doc;
    m_x = 0;
    m_y = 0;
    m_scale = 1.0;
    ref();

    ptr<command> cmd = new cmd_new_interface_bar(this);
    register_menu_entry("new interface bar", "create new interface bar", cmd);
}

void view::register_menu_entry(const string& name, const string& help, 
        ptr<command> proc) {
    static atomic_int cur_id(wxID_HIGHEST);

    int id = ++cur_id;
    m_pop_menu.Append(id, name, help);
    m_menu_proc[id] = proc;
}

view::operator wxWindow*() {
    return dynamic_cast<wxWindow*>(this);
}

wxPoint view::get_mouse_pos() {
    return m_mouse_rpos;
}

wxSize view::get_client_size() {
    wxSize size;
    GetClientSize(&size.x, &size.y);
    int x = 0, y = 0;
    rtransform(x, y, size.x, size.y);
    return size;
}

void view::refresh() {
    Refresh();
}

void view::on_menu(wxCommandEvent& evt) {
    int id = evt.GetId();
    ptr<command> cmd = m_menu_proc[id];
    if (cmd != nullptr) {
        cmd->perform();
    } else {
        char buf[32];
        sprintf(buf, "menu %d not found.", id);
        wxMessageBox(buf);
    }
}

void view::on_mouse_event(wxMouseEvent& evt) {
    wxPoint pos = evt.GetPosition();
    rtransform(pos.x, pos.y);
    ptr<visual> processor = get_mouse_processor(m_mouse_processor, this, 
            m_doc->get_objects(), pos);
    long flag = 0;
    if (evt.LeftIsDown())
        flag |= flag_left_button;
    if (evt.RightIsDown())
        flag |= flag_right_button;
    if (evt.MiddleIsDown())
        flag |= flag_middle_button;

    if (m_mouse_last_processor != processor) {
        processor->on_mouse_move_in(pos.x, pos.y, flag);
        if (m_mouse_last_processor != nullptr)
            m_mouse_last_processor->on_mouse_move_out(pos.x, pos.y, flag);
    }

    if (evt.GetWheelDelta() != 0) {
        int inverted = evt.IsWheelInverted() ? -1 : 1;
        int ds = inverted * evt.GetWheelDelta() / evt.GetWheelRotation();
        processor->on_mouse_wheel(pos.x, pos.y, ds, flag);
    } else if (evt.Moving() || evt.Dragging()) {
        processor->on_mouse_move(pos.x, pos.y, flag);
    } else if (evt.ButtonDown()) {
        processor->on_mouse_down(pos.x, pos.y, flag);
    } else if (evt.ButtonUp()) {
        processor->on_mouse_up(pos.x, pos.y, flag);
        change_select(processor);
    } else if (evt.ButtonDClick()) {
        processor->on_mouse_dclick(pos.x, pos.y, flag);
    }

    m_mouse_last_processor = processor;
    refresh();
}

void view::change_select(ptr<visual> new_object) {
    bool change_select = true;
    for (ptr<visual> pv : m_selected) {
        if (pv == new_object) {
            change_select = false;
            break;
        }
    }
    if (change_select) {
        for (ptr<visual> pv : m_selected) {
            pv->set_focus(false);
        }
        new_object->set_focus(true);

        m_selected.clear();
        m_selected.push_back(new_object);
    }
}

void view::on_key_down(wxKeyEvent& evt) {
    (void) evt;
}

void view::on_key_up(wxKeyEvent& evt) {
    (void) evt;
}

void view::on_char(wxKeyEvent& evt) {
    (void) evt;
}

void view::on_command(wxCommandEvent& evt) {
    (void) evt;
}

void view::on_draw(wxPaintEvent& unused(evt)) {
    on_draw(new dc(this));
}

bool view::on_draw(ptr<dc> pdc) {
    wxRect rect = GetClientRect();

    int x, y, w, h;
    x = rect.x;
    y = rect.y;
    w = rect.width;
    h = rect.height;
    rtransform(x, y, w, h);
    rect = wxRect(x, y, w, h);

    const list<ptr<visual>>& objects = m_doc->get_objects();
    for (ptr<visual> vo : objects) {
        if (vo->is_visable() && vo->intersect(rect)) {
            vo->on_draw(pdc);
        }
    }
    return true;
}

bool view::on_mouse_wheel(long x, long y, long ds, long unused(flag)) {
    int ox = x;
    int oy = y;
    transform(ox, oy);

    m_scale += ds * 0.05;
    if (m_scale < 0.05)
        m_scale = 0.05;

    m_x = 0;
    m_y = 0;
    int rx = m_mouse_rpos.x;
    int ry = m_mouse_rpos.x;
    transform(rx, ry);

    m_x = ox - rx;
    m_y = oy - ry;

    return true;
}

bool view::on_mouse_up(long unused(x), long unused(y), long unused(flag)) {
    m_mouse_status.SetLeftDown(false);
    m_mouse_status.SetMiddleDown(false);
    m_mouse_status.SetRightDown(false);
    release_mouse_event(this);
    return true;
}

bool view::on_mouse_down(long x, long y, long flag) {
    if (flag == flag_right_button) {
        m_mouse_status.SetRightDown(true);
        capture_mouse_event(this);
    } else if (flag == flag_left_button) {
        m_mouse_status.SetLeftDown(true);
        wxPoint pos(x, y);
        transform(pos.x, pos.y);
        PopupMenu(&m_pop_menu, pos);
    }
    return true;
}

bool view::on_mouse_move_in(long unused(x), long unused(y), long unused(flag)) {
    return false;
}

bool view::on_mouse_move_out(long unused(x), long unused(y), long unused(flag)) {
    return false;
}

bool view::on_mouse_move(long x, long y, long unused(flag)) {
    if (m_mouse_status.RightIsDown()) {
        int rx = x;
        int ry = y;
        transform(rx, ry);

        int dx = rx - m_mouse_status.GetX();
        int dy = ry - m_mouse_status.GetY();
        on_move(dx, dy);

        m_mouse_status.SetX(rx);
        m_mouse_status.SetY(ry);
        return true;
    } else {
        int rx = x;
        int ry = y;
        transform(rx, ry);

        m_mouse_status.SetX(rx);
        m_mouse_status.SetY(ry);
        m_mouse_rpos.x = x;
        m_mouse_rpos.y = y;
        return true;
    }
}

bool view::on_mouse_dclick(long unused(x), long unused(y), long unused(flag)) {
    return false;
}

bool view::on_key_up(long unused(key), long unused(flag)) {
    return false;
}

bool view::on_key_down(long unused(key), long unused(flag)) {
    return false;
}

bool view::on_char(long unused(key), long unused(flag)) {
    return false;
}

void view::on_move(long dx, long dy) {
    m_x += dx;
    m_y += dy;
}

void view::on_resize() {

}

void view::set_focus(bool unused(focus)) {

}

bool view::contain(long unused(x), long unused(y)) {
    return true;
}

bool view::intersect(wxRect& unused(rect)) {
    return true;
}


void view::capture_mouse_event(ptr<visual> processor) {
    if (m_mouse_processor == nullptr)
        m_mouse_processor = processor;
}

void view::release_mouse_event(ptr<visual> processor) {
    if (m_mouse_processor == processor)
        m_mouse_processor = nullptr;
}

void view::capture_key_event(ptr<visual> processor) {
    if (m_key_processor == nullptr)
        m_key_processor = processor;
}

void view::release_key_event(ptr<visual> processor) {
    if (m_key_processor == processor)
        m_key_processor = nullptr;
}

void view::set_cursor(wxStockCursor cursor) {
    SetCursor(cursor);
}

ptr<document> view::get_document() const {
    return m_doc;
}

static ptr<visual> get_mouse_processor 
    (ptr<visual> prior, ptr<visual> _default,
    const list<ptr<visual>>& vo, const wxPoint& pos) {

    if (prior != nullptr) {
        return prior;
    }

    list<ptr<visual>>::const_iterator i = vo.end();
    while (i != vo.begin()) {
        --i;
        if ((*i)->is_visable() && (*i)->contain(pos.x, pos.y)) {
            return *i;
        }
    }
    return _default;
}

int view::get_dx() {
    return m_x;
}

int view::get_dy() {
    return m_y;
}

double view::get_scale() {
    return m_scale;
}

void view::transform(int& x, int& y, int& w, int& h, int& r) {
    int dx = get_dx();
    int dy = get_dy();
    double scale = get_scale();

    x *= scale;
    y *= scale;
    w *= scale;
    h *= scale;
    r *= scale;

    x += dx;
    y += dy;
}

void view::transform(int& x, int& y, int& w, int& h) {
    int dx = get_dx();
    int dy = get_dy();
    double scale = get_scale();

    x *= scale;
    y *= scale;
    w *= scale;
    h *= scale;

    x += dx;
    y += dy;
}

void view::transform(int& x, int& y) {
    int dx = get_dx();
    int dy = get_dy();
    double scale = get_scale();

    x *= scale;
    y *= scale;

    x += dx;
    y += dy;
}

void view::transform(int& x, int& y, int& r) {
    int dx = get_dx();
    int dy = get_dy();
    double scale = get_scale();

    x *= scale;
    y *= scale;
    r *= scale;

    x += dx;
    y += dy;
}

void view::rtransform(int& x, int& y, int& w, int& h, int& r) {
    int dx = - get_dx();
    int dy = - get_dy();
    double scale = 1.0 / get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
    w *= scale;
    h *= scale;
    r *= scale;
}

void view::rtransform(int& x, int& y, int& w, int& h) {
    int dx = - get_dx();
    int dy = - get_dy();
    double scale = 1.0 / get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
    w *= scale;
    h *= scale;
}

void view::rtransform(int& x, int& y) {
    int dx = - get_dx();
    int dy = - get_dy();
    double scale = 1.0 / get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
}

void view::rtransform(int& x, int& y, int& r) {
    int dx = - get_dx();
    int dy = - get_dy();
    double scale = 1.0 / get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
    r *= scale;
}

}
