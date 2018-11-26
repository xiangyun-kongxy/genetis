#include "app.hpp"
#include <app/visual_plus/windows/frame.hpp>

IMPLEMENT_APP(app);

using namespace vp;

bool app::OnInit() {
    if (!wxApp::OnInit()) {
        return false;
    }

    frame* fm = new frame();
    fm->Show();

    return true;
}


