#include "app.hpp"
#include <app/visual_plus/windows/main_frame.hpp>
#include <app/visual_plus/windows/win_sash.hpp>
#include <app/visual_plus/windows/win_explorer.hpp>
#include <wx/sashwin.h>
#include <wx/splitter.h>
#include <visual_plus/windows/vo_view.hpp>
#include <visual_plus/container/vo_document.hpp>
#include <visual_plus/ui/visual_objects/vo_box.hpp>

IMPLEMENT_APP(app);

using namespace vp;

bool app::OnInit() {
    if (!wxApp::OnInit()) {
        return false;
    }

    wxFrame* frame = new main_frame();
    frame->SetSize(1024, 768);

    ptr<vo_document> doc = new vo_document("unnamed");
    vo_view* view = new vo_view(doc, frame);
    doc->set_view(view);

    ptr<vo_box> vb1 = new vo_box(wxRect(200, 100, 120, 40));
    ptr<vo_box> vb2 = new vo_box(wxRect(400, 100, 120, 40));
    map<string, ptr<visual_object>>* vos = doc->get_dataobjects();
    (*vos)[vb1->name()] = vb1;
    (*vos)[vb2->name()] = vb2;
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


