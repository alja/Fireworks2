// -*- C++ -*-
//
// Package:     Vertexs
// Class  :     FWVertexProxyBuilder
//
// Implementation:
//     <Notes on implementation>
//
// Original Author:  Chris Jones
//         Created:  Tue Dec  2 14:17:03 EST 2008
//
// user include files// user include files

#include "Fireworks2/Core/interface/FWEventItem.h"
#include "Fireworks2/Core/interface/FWProxyBuilderFactory.h"
#include "Fireworks2/Core/interface/fwLog.h"

#include "Fireworks2/Vertices/interface/REveEllipsoid.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "ROOT/REveViewContext.hxx"
#include "ROOT/REveGeoShape.hxx"
#include "ROOT/REvePointSet.hxx"
#include "ROOT/REveUtil.hxx"
#include "ROOT/REveDataSimpleProxyBuilderTemplate.hxx"

#include "TMatrixDEigen.h"
#include "TMatrixDSym.h"
#include "TDecompSVD.h"
#include "TVectorD.h"
#include "TGeoSphere.h"
using namespace ROOT::Experimental;
class FWVertexProxyBuilder : public REveDataSimpleProxyBuilderTemplate<reco::Vertex>
{
public:
   REGISTER_FWPB_METHODS();

   using REveDataSimpleProxyBuilderTemplate<reco::Vertex>::Build;
   
   virtual void Build(const reco::Vertex& iData, int /*idx*/, ROOT::Experimental::REveElement* iItemHolder, const ROOT::Experimental::REveViewContext* context) override
   {
      printf("building vertex (%f, %f, %f) \n", iData.x(), iData.y(), iData.z());
      std::cout << "vertex error " << iData.error() << std::endl;

      REveGeoManagerHolder gmgr(REveGeoShape::GetGeoManager());


   REvePointSet* pointSet = new REvePointSet();
   pointSet->SetNextPoint( iData.x(), iData.y(), iData.z());  
       SetupAddElement(pointSet, iItemHolder, true);

      
      REveGeoShape* eveEllipsoid = new REveGeoShape();
      TGeoSphere* sp = new TGeoSphere("test", 0.f, 1.f);
      eveEllipsoid->SetShape(sp);
      eveEllipsoid->SetMainTransparency(0);
      reco::Vertex::Error e= iData.error();      
      TMatrixDSym m(3);
      for(int i=0;i<3;i++)
      {
         for(int j=0;j<3;j++)
         {
            m(i,j) = e(i,j);
            eveEllipsoid->RefMainTrans()(i+1, j+1) =  e(i,j);
         }
      }
      float s = 2.f;
      eveEllipsoid->RefMainTrans().SetScale(s, s, s);
       SetupAddElement(eveEllipsoid, iItemHolder, true);
   }
   
};


REGISTER_FW2PROXYBUILDER(FWVertexProxyBuilder, reco::Vertex, "Vertices");
