#ifndef INSTRUMENTALTRACK_HPP
#define INSTRUMENTALTRACK_HPP

#include "MusicalComposition.hpp"

class MUSIC_API InstrumentalTrack : public MusicalComposition {
private:
    std::string _leadInstrument;
    bool _hasSolo;

public:
    InstrumentalTrack(const std::string& title, double duration, const std::string& composer, const std::string& genre,
            const std::string& leadInstrument, bool hasSolo);
    std::string GetLeadInstrument() const;
    bool HasSolo() const;
    void ShowInfo() const override;
    virtual ~InstrumentalTrack();
};

#endif
