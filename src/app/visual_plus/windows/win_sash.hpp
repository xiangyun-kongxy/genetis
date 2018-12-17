#ifndef __win_sash_hpp__
#define __win_sash_hpp__

#include <wx/wx.h>
#include <wx/sashwin.h>
#include <visual_plus/arithmetic/layout/bounded/grid_layout.hpp>

namespace vp {

class win_sash : public wxSashWindow {
public:
    win_sash(wxWindow* parent, wxWindowID id = wxID_ANY);

protected:
    void resize(wxSashEvent& evt);
    void on_size(wxSizeEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

}

#endif