#ifndef C6D6Hit_h
#define C6D6Hit_h

#include <iomanip>

#include "G4Allocator.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"
#include "G4UnitsTable.hh"
#include "G4VHit.hh"
#include "G4VHitsCollection.hh"
#include "G4VVisManager.hh"
#include "G4VisAttributes.hh"

class C6D6Hit : public G4VHit {
 public:
  C6D6Hit();
  virtual ~C6D6Hit();

 public:
  inline void* operator new(size_t);
  inline void operator delete(void* aHit);
  virtual void Draw();
  virtual void Print();

 public:
  inline void SetDepositedEnergy(const G4double e) { eDep = e; }
  inline void SetTimeInteraction(const G4double t) { time = t; }
  inline void SetPositionInteracion(const G4ThreeVector pos) { fPos = pos; }
  inline void SetCopyNumber(const G4int c) { copy_number = c; }
  inline void SetParticleName(const G4String n) { pName = n; }

  inline G4double GetEdep() const { return eDep; }
  inline G4double GetTime() const { return time; }
  inline G4ThreeVector GetPositionInteraction() const { return fPos; }
  inline G4int GetCopyNumber() const { return copy_number; }
  inline G4String GetParticleName() const { return pName; }

 private:
  G4double eDep, time;
  G4int copy_number;
  G4ThreeVector fPos;
  G4String pName;
};

typedef G4THitsCollection<C6D6Hit> C6D6HitCollection;

extern G4ThreadLocal G4Allocator<C6D6Hit>* C6D6HitAllocator;

inline void* C6D6Hit::operator new(size_t) {
  if (!C6D6HitAllocator) {
    C6D6HitAllocator = new G4Allocator<C6D6Hit>;
  }
  return (void*)C6D6HitAllocator->MallocSingle();
}

inline void C6D6Hit::operator delete(void* aHit) {
  C6D6HitAllocator->FreeSingle((C6D6Hit*)aHit);
}

#endif
