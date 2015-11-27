#pragma once

#include<vector>

#include "voxel.hpp"

using namespace std;

class World {
public:

  World();

  Voxel* getVoxel(int i, int j, int k);

  int getSizeX();
  int getSizeY();
  int getSizeZ();

private:
  vector<vector<vector<Voxel *>>> voxels;

  int sizeX = 50;
  int sizeY = 30;
  int sizeZ = 20;

  void generateWorld();
};
