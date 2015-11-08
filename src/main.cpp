
#include "logger.hpp"
#include "world.hpp"

int main(int argc, char *argv[]) {
  Logger::log("Starting", Logger::DEBUG);

  World* world = new World();

  delete world;
  Logger::log("Quitting", Logger::DEBUG);
  return 0;
}
