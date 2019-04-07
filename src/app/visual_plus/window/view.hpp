#ifndef __view_hpp__
#define __view_hpp__

#include <wx/wx.h>
#include <document/document.hpp>
#include <visual_object/visual/visual.hpp>
#include <action/command.hpp>

namespace vp
{

class view : protected wxWindow, public visual {
public:
    view(ptr<document> doc, wxWindow* parent);

public:
    virtual void on_mouse_event(wxMouseEvent& evt);
    virtual void on_key_down(wxKeyEvent& evt);
    virtual void on_key_up(wxKeyEvent& evt);
    virtual void on_char(wxKeyEvent& evt);
    virtual void on_command(wxCommandEvent& evt);
    virtual void on_draw(wxPaintEvent& evt);
    virtual void on_menu(wxCommandEvent& evt);

public:
    virtual bool on_draw(ptr<dc> pdc) override;

    virtual bool on_mouse_wheel(long x, long y, long ds, long flag) override;
    virtual bool on_mouse_up(long x, long y, long flag) override;
    virtual bool on_mouse_down(long x, long y, long flag) override;
    virtual bool on_mouse_move_in(long x, long y, long flag) override;
    virtual bool on_mouse_move_out(long x, long y, long flag) override;
    virtual bool on_mouse_move(long x, long y, long flag) override;
    virtual bool on_mouse_dclick(long x, long y, long flag) override;

    virtual bool on_key_up(long key, long flag) override;
    virtual bool on_key_down(long key, long flag) override;
    virtual bool on_char(long key, long flag) override;

    virtual void on_move(long dx, long dy) override;
    virtual void on_resize() override;
    virtual void set_focus(bool focus) override;

    virtual bool contain(long x, long y) override;
    virtual bool intersect(wxRect& rect) override;

public:
    void capture_mouse_event(ptr<visual> processor);
    void release_mouse_event(ptr<visual> processor);
    void capture_key_event(ptr<visual> processor);
    void release_key_event(ptr<visual> processor);

public:
    operator wxWindow*();
    void refresh();
    wxSize get_client_size();
    void set_cursor(wxStockCursor cursor);

public:
    void transform(int& x, int& y, int& w, int& h, int&r);
    void transform(int& x, int& y, int& w, int& h);
    void transform(int& x, int& y);
    void transform(int& x, int& y, int&r);

    void rtransform(int& x, int& y, int& w, int& h, int&r);
    void rtransform(int& x, int& y, int& w, int& h);
    void rtransform(int& x, int& y);
    void rtransform(int& x, int& y, int&r);
public:
    ptr<document> get_document() const;
    void change_select(ptr<visual> new_object);
    void register_menu_entry(const string& name, const string& help,
            ptr<command> proc);

    wxPoint get_mouse_pos();
public:
    int get_dx();
    int get_dy();
    double get_scale();

protected:
    ptr<document> m_doc;

    ptr<visual> m_mouse_processor;
    ptr<visual> m_mouse_last_processor;
    ptr<visual> m_key_processor;

    map<int, ptr<command>> m_menu_proc;
    wxMenu m_pop_menu;

    list<ptr<visual>> m_selected;

    int m_x;
    int m_y;
    double m_scale;

    wxPoint m_mouse_rpos;
private:
    wxDECLARE_EVENT_TABLE();
};

}

#endif
