#include <vector>
#include "MusicalComposition.hpp"

MusicalComposition::MusicalComposition(const std::string& title, double duration, const std::string& composer, const std::string& genre) : AbstractAudioContent(title, duration), composer(composer), genre(genre) {}

std::string MusicalComposition::GetComposer() const {
  return this->composer;
}
std::string MusicalComposition::GetGenre() const {
  return this->genre;
}

void MusicalComposition::ShowInfo() const {
    printf("Title: %s, Duration: %f, Composer: %s, Genre: %s", title.c_str(), duration, composer.c_str(), genre.c_str());
}

std::string MusicalComposition::GetInfo() const {
  std::vector<char> buf(250);
  snprintf(buf.data(), buf.size(), "Title: %s, Duration: %f, Composer: %s, Genre: %s", title.c_str(), duration, composer.c_str(), genre.c_str());
  std::string t(buf.data());
  return t;
}

MusicalComposition::~MusicalComposition() {}
