#include "InstrumentalTrack.hpp"

InstrumentalTrack::InstrumentalTrack(const std::string& title, double duration, const std::string& composer, const std::string& genre,
        const std::string& leadInstrument, bool hasSolo) : MusicalComposition(title, duration, composer, genre), _leadInstrument(leadInstrument), _hasSolo(hasSolo) {}

std::string InstrumentalTrack::GetLeadInstrument() const {
  return this->_leadInstrument;
}

bool InstrumentalTrack::HasSolo() const {
  return this->_hasSolo;
}

void InstrumentalTrack::ShowInfo() const {
  printf("Instrumental track\n");
  MusicalComposition::ShowInfo();
  printf("\nLead instrument: %s, Has solo: %b", this->_leadInstrument.c_str(), this->_hasSolo);
}

InstrumentalTrack::~InstrumentalTrack() {}
