#pragma once

#include <iostream>
#include <string>

class Logger {
public:
  void add_logs(const std::string &log) { logs += log; }
  void read_logs() { std::cout << logs << std::endl; }
  static Logger &get_instance() {
    static Logger instance;
    return instance;
  }

private:
  Logger() = default;
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
  std::string logs{"\tActivity Logs\n"};
};