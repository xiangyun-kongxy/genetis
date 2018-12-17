#include <visual_plus/windows/win_sash.hpp>

namespace vp {

    wxBEGIN_EVENT_TABLE(win_sash, wxSashWindow)
        EVT_SASH_DRAGGED(wxID_ANY, win_sash::resize)
        EVT_SIZE(win_sash::on_size)
    wxEND_EVENT_TABLE();

    win_sash::win_sash(wxWindow* parent, wxWindowID id)
        : wxSashWindow(parent, id, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME ) {

    }

    void win_sash::resize(wxSashEvent& evt) {
        wxRect rect = evt.GetDragRect();
        wxPoint old = GetPosition();
        switch (evt.GetEdge()) {
        case wxSASH_TOP:
            old.y = rect.GetY();
            break;
        case wxSASH_LEFT:
            old.x = rect.GetX();
            break;
        case wxSASH_RIGHT:
        case wxSASH_BOTTOM:
        case wxSASH_NONE:
            break;
        }
        SetPosition(old);
        SetSize(rect.GetSize());
        Layout();
        if (GetParent() != nullptr) {
            GetParent()->Layout();
        }
    }

    void win_sash::on_size(wxSizeEvent& evt) {
        OnSize(evt);
    }

}