#include<iostream>

#include "logger.hpp"
#include "world.hpp"
#include "CLIWorldPrinter.hpp"
#include "GLWorldDisplay2D.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  Logger::log("Starting", Logger::DEBUG);

  World* world;
  if (argc == 5) {
    world = new World(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
  }
  else if (argc == 4) {
    world = new World(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  }
  else if (argc == 2) {
    world = new World(atoi(argv[1]));
  }
  else {
    world = new World();
  }

  GLWorldDisplay2D::setWorld(world);
  // TODO: Implement setter
  //GLWorldDisplay2D::world = world;

  GLWorldDisplay2D::displayWorld(&argc, argv);

  // int level;
  // while(true) {
  //   cout << "Level between 0 and " << world->getSizeZ() - 1 << ": ";
  //   cin >> level;

  //   if (level == -1 || level > world->getSizeZ() - 1) break;

  //   printer->printWorld(level);
  // }

  delete world;
  Logger::log("Quitting", Logger::DEBUG);
  return 0;
}
