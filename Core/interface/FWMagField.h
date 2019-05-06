#ifndef Fireworks_Tracks_FW2MagField_h
#define Fireworks_Tracks_FW2MagField_h
// -*- C++ -*-
// 
// Simplified model of the CMS detector magnetic field
// 

#include "ROOT/REveTrackPropagator.hxx"

class TH1F;

namespace edm
{
   class EventBase;
}

class FWMagField: public ROOT::Experimental::REveMagField
{
   Float_t GetFieldMag() const;

public:
   enum ESource { kNone, kEvent, kUser };

   FWMagField();
   ~FWMagField() override;

   // get field values
   ROOT::Experimental::REveVector GetField(Float_t x, Float_t y, Float_t z) const override;
   Float_t    GetMaxFieldMag() const override;

   // auto/user behaviour
   void   setUserField(float b) { m_userField = b; }
   float  getUserField() const { return  m_userField; }
   void   setSource(ESource x) { m_source = x; }
   ESource  getSource() const { return m_source; }

   // field model
   void   setReverseState( bool state ){ m_reverse = state; }
   bool   isReverse() const { return m_reverse;}
   void   setSimpleModel( bool simpleModel ){ m_simpleModel = simpleModel; }
   bool   isSimpleModel() const { return m_simpleModel;}

   // field estimate
   void   guessFieldIsOn( bool guess ) const;
   void   guessField( float estimate ) const;
   void   resetFieldEstimate() const;

   void   checkFieldInfo(const edm::EventBase*);
   void   setFFFieldMag(float);

private:
   FWMagField(const FWMagField&) = delete; // stop default
   const FWMagField& operator=(const FWMagField&) = delete; // stop default

   ESource   m_source;
   float     m_userField;
   float     m_eventField;

   bool   m_reverse;
   bool   m_simpleModel;

   // runtime estimate , have to be mutable becuse of GetField() is const
   mutable TH1F  *m_guessValHist;
   mutable int    m_numberOfFieldIsOnEstimates;
   mutable int    m_numberOfFieldEstimates;
   mutable bool   m_updateFieldEstimate;
   mutable float  m_guessedField;
};

#endif
