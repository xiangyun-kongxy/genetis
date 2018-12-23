#ifndef __view_hpp__
#define __view_hpp__

#include <wx/wx.h>
#include <visual_plus/container/vo_document.hpp>

namespace vp
{

class vo_view : wxWindow {
public:
    vo_view(ptr<vo_document> doc, wxWindow* parent);

public:
    virtual void on_mouse_event(wxMouseEvent& evt);
    virtual void on_key_down(wxKeyEvent& evt);
    virtual void on_key_up(wxKeyEvent& evt);
    virtual void on_char(wxKeyEvent& evt);
    virtual void on_command(wxCommandEvent& evt);
    virtual void on_draw(wxPaintEvent& evt);

public:
    ptr<vo_document> get_document() const;

protected:
    ptr<vo_document> m_doc;

private:
    wxDECLARE_EVENT_TABLE();
};

}

#endif