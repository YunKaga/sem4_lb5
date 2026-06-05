#include <fstream>

#include "FilePresenter.hpp"
#include "../domain/MusicalComposition.hpp"
#include "../domain/MusicDisk.hpp"

FilePresenter::FilePresenter(const std::string& filename) : _filename(filename) {};

void FilePresenter::ShowComposition(const MusicalComposition& comp) {
    std::ofstream file(_filename, std::ios::app);
    if (file.is_open()) {
      file << comp.GetInfo() << std::endl;
    }
}

void FilePresenter::ShowDisk(const MusicDisk& disk) {
    std::ofstream file(_filename, std::ios::app);
    if (file.is_open()) {
        file << "\n=== Disk: " << disk.GetDiskName() << " ===" << std::endl;
        file << "Tracks count: " << disk.GetTrackCount() << std::endl;
        file << "Total duration: " << disk.CalculateTotalDuration() << " seconds" << std::endl;
    }
}

void FilePresenter::ShowMessage(const std::string& message) {
    std::ofstream file(_filename, std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
    }
}
