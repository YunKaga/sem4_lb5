#include "CompositionFactory.hpp"
#include "../domain/Song.hpp"
#include "../domain/InstrumentalTrack.hpp"

std::unique_ptr<MusicalComposition> SongFactory::CreateComposition(
    const std::string& title,
    double duration,
    const std::string& composer,
    const std::string& genre
) {
    return CreateSong(title, duration, composer, genre, "Unknown", false);
}

std::unique_ptr<MusicalComposition> SongFactory::CreateSong(
    const std::string& title,
    double duration,
    const std::string& composer,
    const std::string& genre,
    const std::string& vocalist,
    bool hasLyrics
) {
    return std::make_unique<Song>(title, duration, composer, genre, vocalist, hasLyrics);
}

std::unique_ptr<MusicalComposition> InstrumentalFactory::CreateComposition(
    const std::string& title,
    double duration,
    const std::string& composer,
    const std::string& genre
) {
    return CreateInstrumental(title, duration, composer, genre, "Piano", false);
}

std::unique_ptr<MusicalComposition> InstrumentalFactory::CreateInstrumental(
    const std::string& title,
    double duration,
    const std::string& composer,
    const std::string& genre,
    const std::string& leadInstrument,
    bool hasSolo
) {
    return std::make_unique<InstrumentalTrack>(title, duration, composer, genre, leadInstrument, hasSolo);
}
