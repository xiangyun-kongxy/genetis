#include "app.hpp"
#include "frame.hpp"

IMPLEMENT_APP(app);

bool app::OnInit() {
    if (!wxApp::OnInit()) {
        return false;
    }

    frame* frame = new class frame();
    frame->Show();

    return true;
}


