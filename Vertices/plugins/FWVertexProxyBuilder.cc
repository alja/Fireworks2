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

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "ROOT/REveViewContext.hxx"
#include "ROOT/REveDataSimpleProxyBuilderTemplate.hxx"

#include "TMatrixDEigen.h"
#include "TMatrixDSym.h"
#include "TDecompSVD.h"
#include "TVectorD.h"
#include "TGeoSphere.h"

class FWVertexProxyBuilder : public ROOT::Experimental::REveDataSimpleProxyBuilderTemplate<reco::Vertex>
{
   //FWMuonBuilder m_builder;
public:
   REGISTER_FWPB_METHODS();

   using REveDataSimpleProxyBuilderTemplate<reco::Vertex>::Build;
   
   virtual void Build(const reco::Vertex& iData, int /*idx*/, ROOT::Experimental::REveElement* iItemHolder, const ROOT::Experimental::REveViewContext* context) override
   {
      printf("building vertex (%f, %f, %f) \n", iData.x(), iData.y(), iData.z());
      std::cout << "vertex error " << iData.error();
   }
};


REGISTER_FW2PROXYBUILDER(FWVertexProxyBuilder, reco::Vertex, "Vertices");
