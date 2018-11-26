#if !defined(__visual_object_hpp__)
#define __visual_object_hpp__

#include "event_handler.hpp"
#include "vo_status.hpp"
#include <visual_plus/arithmetic/geometry/graph.hpp>
#include <lib/object/managed_object.hpp>
#include <map>

using namespace std;
using namespace kxy;

namespace vp {

class visual_object : public event_handler, public graph {
public:
  virtual void draw() override;
  virtual bool in(ptr<point> pt)override;
  virtual void set_transform(wxAffineMatrix2D& mat) override;

public:
  vo_status get_status() const;
  void set_status(vo_status status);

protected:
  vo_status m_status;
  map<vo_status, multimap<int, ptr<graph>>> m_graphs;
  wxAffineMatrix2D m_mat;
};

} // namespace vp

#endif //__visual_object_hpp__
