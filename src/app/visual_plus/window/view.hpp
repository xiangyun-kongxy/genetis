#ifndef __view_hpp__
#define __view_hpp__

#include <wx/wx.h>
#include <document/document.hpp>
#include <visual_object/visual_object.hpp>

namespace vp
{

class view : public wxWindow {
public:
    view(ptr<document> doc, wxWindow* parent);

public:
    virtual void on_mouse_event(wxMouseEvent& evt);
    virtual void on_key_down(wxKeyEvent& evt);
    virtual void on_key_up(wxKeyEvent& evt);
    virtual void on_char(wxKeyEvent& evt);
    virtual void on_command(wxCommandEvent& evt);
    virtual void on_draw(wxPaintEvent& evt);

public:
    void capture_mouse_event(ptr<visual_object> processor);
    void release_mouse_event(ptr<visual_object> processor);
    void capture_key_event(ptr<visual_object> processor);
    void release_key_event(ptr<visual_object> processor);

public:
    ptr<document> get_document() const;

public:
    int get_dx();
    int get_dy();
    double get_scale();

protected:
    ptr<document> m_doc;
    ptr<visual_object> m_mouse_processor;
    ptr<visual_object> m_mouse_last_processor;
    ptr<visual_object> m_key_processor;

    int m_x;
    int m_y;
    double m_scale;

private:
    wxDECLARE_EVENT_TABLE();
};

}

#endif
