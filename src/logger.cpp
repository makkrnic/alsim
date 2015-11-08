#include "logger.hpp"

#include<iostream>

using namespace std;

void Logger::init() {

}

void Logger::log(const char *message, Severity severity) {
  cout << message << endl;
}
