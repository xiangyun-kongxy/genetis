#include "grid_layout.hpp"
#include <visual_plus/ui/visual_object.hpp>

namespace vp {
grid_layout::grid_layout(int row, int column, 
        initializer_list<double> column_width,
        initializer_list<double> row_height) {
    m_row = row;
    m_column = column;
    m_grids = new grid*[m_row];
    for (int i = 0; i < m_row; ++i) {
        m_grids[i] = new grid[m_column];
        for (int n = 0; n < m_column; ++n) {
            m_grids[i][n].win = nullptr;
            m_grids[i][n].obj = nullptr;
        }
    }
    init_height(row_height);
    init_width(column_width);
}
void grid_layout::init_width(initializer_list<double> widths) {
    double s = 0.0;
    int c = 0;
    for (double width : widths) {
        for (int r = 0; r < m_row; ++r) {
            m_grids[r][c].width= width;
        }
        if (width <= 1.0) {
            s += width;
        } else {
            m_min_size.SetWidth(m_min_size.GetWidth() + width);
        }
        ++c;
    }
    if (c < m_column) {
        double rc = (1.0 - s) / (m_column- c);
        for (; c < m_column; ++c) {
            for (int r = 0; r < m_row; ++r) 
                m_grids[r][c].height = rc;
        }
    }
}

void grid_layout::init_height(initializer_list<double> heights) {
    double s = 0.0;
    int r = 0;
    for (double height : heights) {
        for (int c = 0; c < m_column; ++c) {
            m_grids[r][c].height = height;
        }
        if (height <= 1.0) {
            s += height;
        } else {
            m_min_size.SetHeight(m_min_size.GetHeight() + height);
        }
        ++r;
    }
    if (r < m_row) {
        double rh = (1.0 - s) / (m_row - r);
        for (; r < m_row; ++r) {
            for (int c = 0; c < m_column; ++c) 
                m_grids[r][c].height = rh;
        }
    }
}

void grid_layout::resize(int x, int y, int width, int height) {
    int r_width = width - m_min_size.GetWidth();
    int r_height = height - m_min_size.GetHeight();
    int cx = x;
    int cy = y;
    for (int r = 0; r < m_row; ++r) {
        cx = x;
        int dy = 0;
        for (int c = 0; c < m_column; ++c) {
            if (m_grids[r][c].width > 1)
                m_grids[r][c].real_rect.SetWidth(m_grids[r][c].width);
            else
                m_grids[r][c].real_rect.SetWidth(r_width*m_grids[r][c].width);
            if (m_grids[r][c].height> 1)
                m_grids[r][c].real_rect.SetHeight(m_grids[r][c].height);
            else
                m_grids[r][c].real_rect.SetHeight(r_height*m_grids[r][c].height);
            m_grids[r][c].real_rect.SetX(cx);
            m_grids[r][c].real_rect.SetY(cy);
            cx += m_grids[r][c].real_rect.GetWidth();
            dy = m_grids[r][c].real_rect.GetHeight();
        }
        cy += dy;
    }
}

void grid_layout::apply() {
    for (int r = 0; r < m_row; ++r) {
        for (int c = 0; c < m_column; ++c) {
            if (m_grids[r][c].win == nullptr && m_grids[r][c].obj == nullptr)
                continue;

            wxRect rect = m_grids[r][c].real_rect;
            if (m_grids[r][c].win != nullptr) {
                m_grids[r][c].win->SetPosition(rect.GetPosition());
                m_grids[r][c].win->SetSize(rect.GetSize());
            } else if (m_grids[r][c].obj->is_kind_of("visual_object")) {
                ((ptr<visual_object>)m_grids[r][c].obj)->set_rect(rect);
            } else if (m_grids[r][c].obj->is_kind_of("box_layout")) {
                ((ptr<box_layout>)m_grids[r][c].obj)->resize(rect.x, rect.y, rect.width, rect.height);
                ((ptr<box_layout>)m_grids[r][c].obj)->apply();
            }
        }
    }
}

void grid_layout::add(ptr<visual_object> vo, int position) {
    int row = position / m_column;
    int column = position % m_column;
    m_grids[row][column].obj = vo;
    m_grids[row][column].win = nullptr;
}

void grid_layout::add(ptr<box_layout> box, int position) {
    int row = position / m_column;
    int column = position % m_column;
    m_grids[row][column].obj = box;
    m_grids[row][column].win = nullptr;
}

void grid_layout::add(wxWindow* win, int position) {
    int row = position / m_column;
    int column = position % m_column;
    m_grids[row][column].obj = nullptr;
    m_grids[row][column].win = win;
}

}
