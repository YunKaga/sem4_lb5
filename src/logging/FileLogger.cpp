#include "FileLogger.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>

FileLogger::FileLogger(const std::string& filename) : _filename(filename) {}

std::string FileLogger::GetTimestamp() const {
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  std::stringstream ss;
  ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
  return ss.str();
}

void FileLogger::LogInfo(const std::string& message) {
  std::ofstream file(_filename, std::ios::app);
  if (file.is_open()) {
    file << "[" << GetTimestamp() << "] [INFO] " << message << "\n";
  }
}

void FileLogger::LogError(const std::string& message) {
  std::ofstream file(_filename, std::ios::app);
  if (file.is_open()) {
    file << "[" << GetTimestamp() << "] [ERROR] " << message << "\n";
  }
}

void FileLogger::LogDebug(const std::string& message) {
  std::ofstream file(_filename, std::ios::app);
  if (file.is_open()) {
    file << "[" << GetTimestamp() << "] [DEBUG] " << message << "\n";
  }
}
