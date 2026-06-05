#ifndef DISKSTORAGE_HPP
#define DISKSTORAGE_HPP

#include "MusicLibraryAPI.hpp"
#include <string>

class MusicDisk;

class MUSIC_API DiskStorage {
public:
  static void SaveDiskInfo(const MusicDisk& disk, const std::string& filename);
  static MusicDisk LoadDiskInfo(const std::string& filename);
};

#endif
