#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <string>
#include "../../include/MusicLibraryAPI.hpp"

class MUSIC_API ILogger {
public:
  virtual ~ILogger() = default;

  virtual void LogInfo(const std::string& message) = 0;
  virtual void LogError(const std::string& message) = 0;
  virtual void LogDebug(const std::string& message) = 0;
};

#endif
