#ifndef IPRESENTER_HPP
#define IPRESENTER_HPP

#include <string>

class MusicalComposition;
class MusicDisk;

class IPresenter {
public:
  virtual ~IPresenter() = default;

  virtual void ShowComposition(const MusicalComposition& comp) = 0;
  virtual void ShowDisk(const MusicDisk& disk) = 0;
  virtual void ShowMessage(const std::string& message) = 0;
};

#endif
