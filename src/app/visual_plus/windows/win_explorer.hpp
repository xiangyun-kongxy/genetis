#ifndef __win_explorer_hpp__
#define __win_explorer_hpp__

#include <wx/wx.h>
#include "win_sash.hpp"

namespace vp {

class win_explorer : public win_sash {
public:
    win_explorer(wxWindow* parent);

protected:
    wxToolBar* m_switcher;
};

}

#endif