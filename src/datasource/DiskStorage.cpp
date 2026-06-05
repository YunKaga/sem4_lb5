#include "DiskStorage.hpp"
#include "../domain/MusicDisk.hpp"
#include <fstream>
#include <iostream>

void DiskStorage::SaveDiskInfo(const MusicDisk& disk, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Disk: " << disk.GetDiskName() << std::endl;
        file << "Tracks: " << disk.GetTrackCount() << std::endl;
        file << "Total Duration: " << disk.CalculateTotalDuration() << "s" << std::endl;
        file.close();
        std::cout << "Disk info saved to " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open file " << filename << " for writing" << std::endl;
    }
}

MusicDisk DiskStorage::LoadDiskInfo(const std::string& filename) {
    return MusicDisk("Loaded Disk", 80); // заскос на будущий функционал
}
