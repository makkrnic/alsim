#pragma once

#include<vector>

#include "voxel.hpp"

using namespace std;

class World {
public:

  World();

private:
  vector<vector<vector<Voxel *>>> voxels;

  void generateWorld();
};
