#pragma once

#include "world.hpp"
#include "voxel.hpp"

class CLIWorldPrinter {
public:
  CLIWorldPrinter(World* world);
  void printWorld(int level);

private:
  World* world;
};
