#ifndef ROOT_REveEllipsoid
#define ROOT_REveEllipsoid

#include "ROOT/REveShape.hxx"
#include "ROOT/REveVector.hxx"
#include "ROOT/REveTrans.hxx"
#include "TMatrixDSym.h"

using namespace ROOT::Experimental;
//------------------------------------------------------------------------------
// REveEllipsoid
//------------------------------------------------------------------------------

class REveEllipsoid : public REveShape {
protected:
  REveVector fPos;
  REveVector fExtent3D;
  REveTrans fEMtx;
   
public:
   REveEllipsoid(const Text_t* n = "REveEllipsoid", const Text_t* t = "") {}
  ~REveEllipsoid() override {}

  REveVector& RefPos() { return fPos; }
  REveVector& RefExtent3D() { return fExtent3D; }  // cached member for bbox and 3D rendering
  REveTrans& RefEMtx() { return fEMtx; }

  ClassDef(REveEllipsoid, 0);  // Short description.
};


#endif
