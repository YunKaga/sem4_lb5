#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP

#include "ILogger.hpp"
#include <iostream>

class MUSIC_API ConsoleLogger : public ILogger {
public:
  void LogInfo(const std::string& message) override {
    std::cout << "[INFO] " << message << std::endl;
  }
  void LogError(const std::string& message) override {
    std::cout << "[ERROR] " << message << std::endl;
  }
  void LogDebug(const std::string& message) override {
    std::cout << "[DEBUG] " << message << std::endl;
  }
};

#endif
