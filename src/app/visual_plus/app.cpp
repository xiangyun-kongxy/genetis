#include "app.hpp"
#include <window/view.hpp>
#include <document/document.hpp>
#include <visual_object/instace/interface_bar.hpp>

IMPLEMENT_APP(app);

using namespace vp;

bool app::OnInit() {
    if (!wxApp::OnInit()) {
        return false;
    }

    wxFrame* frame = new wxFrame(nullptr, wxID_DEFAULT, "visual plus");
    frame->SetSize(1024, 768);

    ptr<document> doc = new document("unnamed");
    view* view = new class view(doc, frame);
    doc->set_view(view);


/*
    wxWindow* main = new wxWindow(frame, wxID_ANY);
    main->SetAutoLayout(true);

    wxSashWindow* ltwin = new win_sash(main, wxID_ANY);
    wxSashWindow* lbwin = new win_sash(main, wxID_ANY);
    wxSplitterWindow* rwin = new wxSplitterWindow(main, wxID_ANY);

    wxLayoutConstraints* lt = new wxLayoutConstraints();
    lt->left.Absolute(0);
    lt->top.Absolute(0);
    lt->right.AsIs();
    lt->bottom.AsIs();
    ltwin->SetSize(360, 24);
    ltwin->SetSashVisible(wxSASH_RIGHT, true);
    ltwin->SetSashVisible(wxSASH_BOTTOM, true);
    ltwin->SetConstraints(lt);
    ltwin->SetAutoLayout(true);

    wxLayoutConstraints* lb = new wxLayoutConstraints();
    lb->left.Absolute(0);
    lb->top.Below(ltwin, 8);
    lb->right.SameAs(ltwin, wxRight);
    lb->bottom.SameAs(main, wxBottom);
    lbwin->SetSashVisible(wxSASH_RIGHT, true);
    lbwin->SetSashVisible(wxSASH_TOP, true);
    lbwin->SetConstraints(lb);
    lbwin->SetAutoLayout(true);

    wxLayoutConstraints* r = new wxLayoutConstraints();
    r->left.RightOf(ltwin, 8);
    r->top.Absolute(0);
    r->right.SameAs(main, wxRight);
    r->bottom.SameAs(main, wxBottom);
    rwin->SetConstraints(r);
    rwin->SplitHorizontally(new wxWindow(rwin, wxID_ANY), new wxWindow(rwin, wxID_ANY));
    // rwin->SetWindowStyle(wxSP_LIVE_UPDATE | wxBORDER_THEME | wxSP_3D);
    // rwin->SetBackgroundColour(*wxWHITE);
    rwin->SetAutoLayout(true);
    */

    frame->Show();

    return true;
}


