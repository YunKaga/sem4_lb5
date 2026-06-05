#include "AudioContent.hpp"

#include <cstdio>

AbstractAudioContent::AbstractAudioContent(const std::string& title, double duration) : title(title), duration(duration){}

std::string AbstractAudioContent::GetTitle() const {
    return this->title;
}

double AbstractAudioContent::GetDuration() const {
    return this->duration;
}

void AbstractAudioContent::ShowInfo() const {
    printf("Title: %s, Duration: %f", title.c_str(), duration);
}

AbstractAudioContent::~AbstractAudioContent() {}
