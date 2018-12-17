#include "win_explorer.hpp"

namespace vp {

win_explorer::win_explorer(wxWindow* parent)
    : win_sash(parent) {
    wxImage image("/Users/kongxiangyun/Pictures/tfsprivate.jpg");
    double scale_width = (double) image.GetWidth() / 24;
    double scale_height = (double) image.GetHeight() / 24;
    double scale = scale_width > scale_height ? scale_width : scale_height;
    m_switcher = new wxToolBar(this, wxID_ANY);
    m_switcher->SetToolBitmapSize(wxSize(24, 24));
    m_switcher->AddTool(0, "t1", wxBitmap(image, -1, scale));
    m_switcher->AddTool(0, "t2", wxBitmap(image, -1, scale));
    m_switcher->AddTool(0, "t3", wxBitmap(image, -1, scale));

    ptr<box_layout> layout = new grid_layout(2, 1, {1.0}, {36, 1.0});
    layout->add(m_switcher, 0);
    layout->add(new wxWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_DOUBLE |wxBORDER_STATIC), 1);
    ptr<box_layout> main = new grid_layout(1, 2, {360, 1.0}, {1.0});
    main->add(layout, 0);
    main->add(new wxWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_DOUBLE), 1);
}

}