#pragma once

#define BOOST_LOG_DYN_LINK 1

class Logger {
public:
  enum Severity {
    DEBUG,
    INFO,
    NOTICE,
    WARN,
    ERROR,
    CRIT,
    ALERT,
    EMERG
  };

  static void init();
  static void log(const char *message, Severity severity);
};
