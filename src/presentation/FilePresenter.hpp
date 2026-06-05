#ifndef FILEPRESENTER_HPP
#define FILEPRESENTER_HPP

#include "IPresenter.hpp"

class FilePresenter : public IPresenter {
private:
  std::string _filename;

public:
  explicit FilePresenter(const std::string& filename = "output.txt");

  void ShowComposition(const MusicalComposition& comp) override;
  void ShowDisk(const MusicDisk& disk) override;
  void ShowMessage(const std::string& message) override;
};

#endif
