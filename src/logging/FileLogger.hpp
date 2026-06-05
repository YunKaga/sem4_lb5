#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include "ILogger.hpp"

class MUSIC_API FileLogger : public ILogger {
private:
  std::string _filename;

  std::string GetTimestamp() const;

public:
  explicit FileLogger(const std::string& filename = "app.log");

  void LogInfo(const std::string& message) override;
  void LogError(const std::string& message) override;
  void LogDebug(const std::string& message) override;
};

#endif
