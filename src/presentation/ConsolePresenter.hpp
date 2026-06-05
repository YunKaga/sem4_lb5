#ifndef CONSOLEPRESENTER_HPP
#define CONSOLEPRESENTER_HPP

#include "IPresenter.hpp"

class ConsolePresenter : public IPresenter {
public:
  void ShowComposition(const MusicalComposition& comp) override;
  void ShowDisk(const MusicDisk& disk) override;
  void ShowMessage(const std::string& message) override;
};

#endif
