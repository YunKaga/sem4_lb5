#ifndef COMPOSITIONFACTORY_HPP
#define COMPOSITIONFACTORY_HPP

#include <memory>
#include <string>

#include "MusicLibraryAPI.hpp"

class MusicalComposition;

class MUSIC_API CompositionFactory {
  public:
    virtual ~CompositionFactory() = default;

    virtual std::unique_ptr<MusicalComposition> CreateComposition(
        const std::string& title,
        double duration,
        const std::string& composer,
        const std::string& genre
        ) = 0;
};

class MUSIC_API SongFactory : public CompositionFactory {
  public:
    std::unique_ptr<MusicalComposition> CreateComposition (
        const std::string& title,
        double duration,
        const std::string& composer,
        const std::string& genre
        ) override;

    std::unique_ptr<MusicalComposition> CreateSong(
        const std::string& title,
        double duration,
        const std::string& composer,
        const std::string& genre,
        const std::string& vocalist,
        bool hasLyrics
        );
};

class MUSIC_API InstrumentalFactory : public CompositionFactory {
  public:
    std::unique_ptr<MusicalComposition> CreateComposition(
        const std::string& title,
        double duration,
        const std::string& composer,
        const std::string& genre
        ) override;

    std::unique_ptr<MusicalComposition> CreateInstrumental(
        const std::string& title,
        double duration,
        const std::string& composer,
        const std::string& genre,
        const std::string& leadInstrument,
        bool hasSolo
        );
};

#endif
