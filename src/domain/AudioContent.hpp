#ifndef AUDIOCONTENT_HPP
#define AUDIOCONTENT_HPP

#include <string>
#include "MusicLibraryAPI.hpp"

class MUSIC_API AbstractAudioContent {
protected:
    std::string title;
    double duration;

public:
    AbstractAudioContent(const std::string& title, double duration);
    std::string GetTitle() const;
    double GetDuration() const;
    virtual void ShowInfo() const;
    virtual ~AbstractAudioContent();
};

#endif
