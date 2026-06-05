#include "MusicDisk.hpp"

MusicDisk::MusicDisk(const std::string& diskName, double capacity) : _diskName(diskName), _capacity(capacity) {}

std::string MusicDisk::GetDiskName() const {
  return this->_diskName;
}

void MusicDisk::AddTrack(std::shared_ptr<MusicalComposition> track) {
    _tracks.push_back(track);
}

double MusicDisk::CalculateTotalDuration() const {
    double total = 0;
    for (const auto& track : _tracks) {
        total += track->GetDuration();
    }

    return total;
}

int MusicDisk::GetTrackCount() const {
    return this->_tracks.size();
}

void MusicDisk::ShowAllTracks() const {
    for (const auto& track : _tracks) {
        track->ShowInfo();
        printf("\n");
    }
}

std::shared_ptr<MusicalComposition> MusicDisk::GetTrack(int index) const {
    if (index >= 0 && this->_tracks.size()) {
        return this->_tracks[index];
    };
    return nullptr;
}

bool MusicDisk::RemoveTrack(int index) {
    if (index >= 0 && index < _tracks.size()) {
        _tracks.erase(_tracks.begin() + index);
        return true;
    }
    return false;
}

bool MusicDisk::UpdateTrack(int index, std::shared_ptr<MusicalComposition> newTrack) {
    if (index >= 0 && index < _tracks.size()) {
        _tracks[index] = newTrack;
        return true;
    }
    return false;
}

MusicDisk::~MusicDisk() {}
