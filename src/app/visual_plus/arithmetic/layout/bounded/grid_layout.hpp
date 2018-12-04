#ifndef __grid_layout_hpp__
#define __grid_layout_hpp__

#include "box_layout.hpp"

using namespace std;
namespace vp {

class grid_layout : public box_layout {
public:
    grid_layout(int row, int column, initializer_list<double> row_height, 
            initializer_list<double> column_width);

public:
    virtual void resize(int x, int y, int width, int height);

public:
    virtual void apply() override;
    virtual void add(ptr<visual_object> vo, int position) override;
    virtual void add(ptr<box_layout> box, int position) override;
    
    virtual wxSize min_size() const override;

private: 
    void init_width(initializer_list<double> widths);
    void init_height(initializer_list<double> heights);

protected:
    struct grid {
        double height;
        double width;
        ptr<object> obj;
        wxRect real_rect;
    };

protected:
    grid** m_grids;
    int m_row;
    int m_column;
    wxSize m_min_size;
};

}

#endif // __grid_layout_hpp__
