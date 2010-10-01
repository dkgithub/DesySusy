#include "SUSYBSMAnalysis/DesySusy/interface/SusyDESY_Module.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/RecoCandidate/interface/IsoDeposit.h"

SusyDESY_Electrons::SusyDESY_Electrons(const edm::ParameterSet& iConfig)
  : Prefix( iConfig.getParameter<string> ("Prefix") ),
    Suffix( iConfig.getParameter<string> ("Suffix") ),
    PatElectrons( iConfig.getParameter<edm::InputTag> ("PatElectrons") )
{
  produces <bool>                 ( Prefix + "PatElectronsHandleValid" + Suffix );

  produces <std::vector<double> > ( Prefix + "SCrawEnergy"             + Suffix ); 
  produces <std::vector<double> > ( Prefix + "SCetaWidth"              + Suffix );
  produces <std::vector<double> > ( Prefix + "SCphiWidth"              + Suffix );
  produces <std::vector<double> > ( Prefix + "SCpreshowerEnergy"       + Suffix );

  //all variables you want to be added to the ntuple by your module
  produces <std::vector<double> > ( Prefix + "GenMatched"              + Suffix );
  produces <std::vector<double> > ( Prefix + "GenPdgId"                + Suffix );
  produces <std::vector<double> > ( Prefix + "GenStatus"               + Suffix );

  produces <std::vector<float> > ( Prefix + "SimpleEleId95relIso" + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId90relIso" + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId85relIso" + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId80relIso" + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId70relIso" + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId60relIso" + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId95cIso"   + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId90cIso"   + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId85cIso"   + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId80cIso"   + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId70cIso"   + Suffix );
  produces <std::vector<float> > ( Prefix + "SimpleEleId60cIso"   + Suffix );
}

void SusyDESY_Electrons::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
  std::auto_ptr<bool>                 handleValid       ( new bool(false)           );

  std::auto_ptr<std::vector<double> > SCrawEnergy       ( new std::vector<double>() );
  std::auto_ptr<std::vector<double> > SCetaWidth        ( new std::vector<double>() );
  std::auto_ptr<std::vector<double> > SCphiWidth        ( new std::vector<double>() );
  std::auto_ptr<std::vector<double> > SCpreshowerEnergy ( new std::vector<double>() );

  //all variables you want to be added to the ntuple by your module

  std::auto_ptr<std::vector<double> > GenMatched         ( new std::vector<double>() );
  std::auto_ptr<std::vector<double> > GenPdgId           ( new std::vector<double>() );
  std::auto_ptr<std::vector<double> > GenStatus          ( new std::vector<double>() );

  std::auto_ptr<std::vector<float> > simpleEleId95relIso ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId90relIso ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId85relIso ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId80relIso ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId70relIso ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId60relIso ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId95cIso   ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId90cIso   ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId85cIso   ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId80cIso   ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId70cIso   ( new std::vector<float>() );
  std::auto_ptr<std::vector<float> > simpleEleId60cIso   ( new std::vector<float>() );

  edm::Handle<std::vector<pat::Electron> > ElColl;
  iEvent.getByLabel(PatElectrons, ElColl);

  if(ElColl.isValid()){
    *handleValid.get() = true;
    //you might do here something to get the variables you want to add, for example

    for(std::vector<pat::Electron>::const_iterator el = ElColl->begin(); el!=ElColl->end(); el++) {

      SCrawEnergy->push_back(el->superCluster()->rawEnergy());
      SCetaWidth->push_back(el->superCluster()->etaWidth());	
      SCphiWidth->push_back(el->superCluster()->phiWidth());
      SCpreshowerEnergy->push_back(el->superCluster()->preshowerEnergy());
      
      simpleEleId95relIso->push_back(el->electronID("simpleEleId95relIso"));
      simpleEleId90relIso->push_back(el->electronID("simpleEleId90relIso"));
      simpleEleId85relIso->push_back(el->electronID("simpleEleId85relIso"));
      simpleEleId80relIso->push_back(el->electronID("simpleEleId80relIso"));
      simpleEleId70relIso->push_back(el->electronID("simpleEleId70relIso"));
      simpleEleId60relIso->push_back(el->electronID("simpleEleId60relIso"));
      simpleEleId95cIso  ->push_back(el->electronID("simpleEleId95cIso"  ));
      simpleEleId90cIso  ->push_back(el->electronID("simpleEleId90cIso"  ));
      simpleEleId85cIso  ->push_back(el->electronID("simpleEleId85cIso"  ));
      simpleEleId80cIso  ->push_back(el->electronID("simpleEleId80cIso"  ));
      simpleEleId70cIso  ->push_back(el->electronID("simpleEleId70cIso"  ));
      simpleEleId60cIso  ->push_back(el->electronID("simpleEleId60cIso"  ));
      
      if(el->genLepton()){
	GenMatched->push_back(1);
	GenPdgId->push_back(el->genLepton()->pdgId());
	GenStatus->push_back(el->genLepton()->status());
      }
      else{
	GenMatched->push_back(0);
	GenPdgId->push_back(0);
	GenStatus->push_back(-1);
      }
      //cout<<"genMatched.back() = " << genMatched << endl;
      //cout<<"genPdgId.back()   = " << genPdgId.back() << endl;
      //cout<<"genStatus.back()  = " << genStatus.back() << endl;
      //cout<<endl;
    }
  }

  iEvent.put( handleValid       , Prefix + "PatElectronsHandleValid" + Suffix );

  iEvent.put( SCrawEnergy       , Prefix + "SCrawEnergy"             + Suffix );
  iEvent.put( SCetaWidth        , Prefix + "SCetaWidth"              + Suffix );
  iEvent.put( SCphiWidth        , Prefix + "SCphiWidth"              + Suffix );
  iEvent.put( SCpreshowerEnergy , Prefix + "SCpreshowerEnergy"       + Suffix );

  //all variables you want to be added to the ntuple by your module
  iEvent.put( GenMatched        , Prefix + "GenMatched"              + Suffix );
  iEvent.put( GenPdgId          , Prefix + "GenPdgId"                + Suffix );
  iEvent.put( GenStatus         , Prefix + "GenStatus"               + Suffix );

  iEvent.put( simpleEleId95relIso, Prefix + "SimpleEleId95relIso"+ Suffix );
  iEvent.put( simpleEleId90relIso, Prefix + "SimpleEleId90relIso"+ Suffix );
  iEvent.put( simpleEleId85relIso, Prefix + "SimpleEleId85relIso"+ Suffix );
  iEvent.put( simpleEleId80relIso, Prefix + "SimpleEleId80relIso"+ Suffix );
  iEvent.put( simpleEleId70relIso, Prefix + "SimpleEleId70relIso"+ Suffix );
  iEvent.put( simpleEleId60relIso, Prefix + "SimpleEleId60relIso"+ Suffix );
  iEvent.put( simpleEleId95cIso  , Prefix + "SimpleEleId95cIso"  + Suffix );
  iEvent.put( simpleEleId90cIso  , Prefix + "SimpleEleId90cIso"  + Suffix );
  iEvent.put( simpleEleId85cIso  , Prefix + "SimpleEleId85cIso"  + Suffix );
  iEvent.put( simpleEleId80cIso  , Prefix + "SimpleEleId80cIso"  + Suffix );
  iEvent.put( simpleEleId70cIso  , Prefix + "SimpleEleId70cIso"  + Suffix );
  iEvent.put( simpleEleId60cIso  , Prefix + "SimpleEleId60cIso"  + Suffix );
}

void SusyDESY_Electrons::beginJob(){}



SusyDESY_Muons::SusyDESY_Muons(const edm::ParameterSet& iConfig)
  : Prefix( iConfig.getParameter<string> ("Prefix") ),
    Suffix( iConfig.getParameter<string> ("Suffix") ),
    PatMuons( iConfig.getParameter<edm::InputTag> ("PatMuons") )
{
  produces <bool>                   ( Prefix + "PatMuonsHandleValid"                 + Suffix );

  produces <std::vector<double> >   ( Prefix + "HcalIsoDep"                          + Suffix );
  produces <std::vector<double> >   ( Prefix + "EcalIsoDep"                          + Suffix );

  produces <std::vector<unsigned> > ( Prefix + "GlobalTrackNumberOfValidTrackerHits" + Suffix );
  produces <std::vector<double> >   ( Prefix + "TrackD0"                             + Suffix );

  //all variables you want to be added to the ntuple by your module
}

void SusyDESY_Muons::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {

  std::auto_ptr<bool>                 handleValid ( new bool(false)           );
  std::auto_ptr<std::vector<unsigned> > globalTrackNHVIT ( new std::vector<unsigned>() );
  std::auto_ptr<std::vector<double> > muonEcalIsoDep ( new std::vector<double>() );
  std::auto_ptr<std::vector<double> > muonHcalIsoDep ( new std::vector<double>() );

  std::auto_ptr<std::vector<double> > muonTrackD0 ( new std::vector<double>() );

  //all variables you want to be added to the ntuple by your module

  edm::Handle<std::vector<pat::Muon> > MuColl;
  iEvent.getByLabel(PatMuons, MuColl);

  if(MuColl.isValid()){
    *handleValid.get() = true;
    //you might do here something to get the variables you want to add, for example

    for(std::vector<pat::Muon>::const_iterator mu = MuColl->begin(); mu!=MuColl->end(); mu++) {

      if(mu->ecalIsoDeposit() && mu->hcalIsoDeposit()){//this is needed to avoid the code seg faulting in 341 - NM 05/01/10
	muonEcalIsoDep->push_back(mu->ecalIsoDeposit()->candEnergy());
	muonHcalIsoDep->push_back(mu->hcalIsoDeposit()->candEnergy());
      }
      else {
	muonEcalIsoDep->push_back(-1);
	muonHcalIsoDep->push_back(-1);
      }
      bool global = mu->globalTrack().isNonnull();
      bool tracker= mu->innerTrack().isNonnull();
      globalTrackNHVIT->push_back( global ? mu->globalTrack()->hitPattern().numberOfValidTrackerHits() : 0);
      muonTrackD0->push_back( tracker ? mu->track()->d0() : 999999999. );
    }
  }
  iEvent.put( handleValid, Prefix + "PatMuonsHandleValid" + Suffix );

  iEvent.put( muonEcalIsoDep  , Prefix + "EcalIsoDep"                               + Suffix );
  iEvent.put( muonHcalIsoDep  , Prefix + "HcalIsoDep"                               + Suffix );

  iEvent.put( muonTrackD0     , Prefix + "TrackD0"                                  + Suffix );
  iEvent.put( globalTrackNHVIT, Prefix + "GlobalTrackNumberOfValidTrackerHits"      + Suffix );

  //all variables you want to be added to the ntuple by your module
}

void SusyDESY_Muons::beginJob(){}

