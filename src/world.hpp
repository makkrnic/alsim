#pragma once

#include<vector>

#include "voxel.hpp"

using namespace std;

class World {
public:

  World()
    : World(DEFAULT_WORLD_SIZE_X, DEFAULT_WORLD_SIZE_Y, DEFAULT_WORLD_SIZE_Z, DEFAULT_WORLD_WATER_LEVEL) {}
  World(unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ)
    : World(sizeX, sizeY, sizeZ, DEFAULT_WORLD_WATER_LEVEL) {}
  World(unsigned int waterLevel)
    : World(DEFAULT_WORLD_SIZE_X, DEFAULT_WORLD_SIZE_Y, DEFAULT_WORLD_SIZE_Z, waterLevel) {}
  World(unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ, unsigned int waterLevel);

  Voxel* getVoxel(int i, int j, int k);

  unsigned int getSizeX();
  unsigned int getSizeY();
  unsigned int getSizeZ();

private:
  static unsigned const DEFAULT_WORLD_SIZE_X = 50;
  static unsigned const DEFAULT_WORLD_SIZE_Y = 30;
  static unsigned const DEFAULT_WORLD_SIZE_Z = 20;
  static unsigned const DEFAULT_WORLD_WATER_LEVEL = 5;

  vector<vector<vector<Voxel *>>> voxels;

  unsigned int sizeX;
  unsigned int sizeY;
  unsigned int sizeZ;
  unsigned int waterLevel;

  void generateWorld();
};
