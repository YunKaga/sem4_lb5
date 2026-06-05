#include "LoggerFactory.hpp"

#include "../logging/ConsoleLogger.hpp"
#include "../logging/FileLogger.hpp"

std::unique_ptr<ILogger> ConsoleLoggerFactory::CreateLogger() {
    return std::make_unique<ConsoleLogger>();
}

FileLoggerFactory::FileLoggerFactory(const std::string& filename) 
    : _filename(filename) {}

std::unique_ptr<ILogger> FileLoggerFactory::CreateLogger() {
    return std::make_unique<FileLogger>(_filename);
}
