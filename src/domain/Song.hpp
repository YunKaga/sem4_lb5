#ifndef SONG_HPP
#define SONG_HPP

#include "MusicalComposition.hpp"

class MUSIC_API Song : public MusicalComposition {
private:
    std::string _vocalist;
    bool _hasLyrics;

public:
    Song(const std::string& title, double duration, const std::string& composer, const std::string& genre,
            const std::string& vocalist, bool hasLyrics);
    std::string GetVocalist() const;
    bool HasLyrics() const;
    void ShowInfo() const override;
    virtual ~Song();
};

#endif
