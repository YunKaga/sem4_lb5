#include "ConsolePresenter.hpp"
#include "../domain/MusicalComposition.hpp"
#include "../domain/MusicDisk.hpp"

void ConsolePresenter::ShowComposition(const MusicalComposition& comp) {
  comp.ShowInfo();
  printf("\n");
}

void ConsolePresenter::ShowDisk(const MusicDisk& disk) {
  disk.ShowAllTracks();
  printf("\n");
}

void ConsolePresenter::ShowMessage(const std::string& message) {
  printf("%s", message.c_str());
}
