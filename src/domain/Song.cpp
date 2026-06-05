#include "Song.hpp"

Song::Song(const std::string& title, double duration, const std::string& composer, const std::string& genre,
        const std::string& vocalist, bool hasLyrics) 
    : MusicalComposition(title, duration, composer, genre), _vocalist(vocalist), _hasLyrics(hasLyrics) {}

std::string Song::GetVocalist() const {
    return this->_vocalist;
}

bool Song::HasLyrics() const {
    return this->_hasLyrics;
}

void Song::ShowInfo() const {
  printf("Song\n");
  MusicalComposition::ShowInfo();
  printf("\nVocalist: %s, Has lyrics: %b", this->_vocalist.c_str(), this->_hasLyrics);
}

Song::~Song() {}
