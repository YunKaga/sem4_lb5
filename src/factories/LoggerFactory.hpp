#ifndef LOGGERFACTORY_HPP
#define LOGGERFACTORY_HPP

#include <memory>
#include <string>

#include "MusicLibraryAPI.hpp"
#include "../logging/ILogger.hpp"

class MUSIC_API LoggerFactory {
public:
  virtual ~LoggerFactory() = default;

  virtual std::unique_ptr<ILogger> CreateLogger() = 0;
};

class MUSIC_API ConsoleLoggerFactory : public LoggerFactory {
public:
  std::unique_ptr<ILogger> CreateLogger() override;
};

class MUSIC_API FileLoggerFactory : public LoggerFactory {
private:
  std::string _filename;

public:
  explicit FileLoggerFactory(const std::string& filename = "app.log");

  std::unique_ptr<ILogger> CreateLogger() override;
};

#endif
