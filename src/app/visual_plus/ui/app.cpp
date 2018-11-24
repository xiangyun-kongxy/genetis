#include "app.hpp"
#include "frame.hpp"

IMPLEMENT_APP(app);

using namespace vp;

bool app::OnInit() {
    if (!wxApp::OnInit()) {
        return false;
    }

    frame* fm = new frame("mainf");
    fm->Show();

    return true;
}


