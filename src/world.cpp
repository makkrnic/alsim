#include "world.hpp"

#include<iostream>
#include<random>
#include<noise/noise.h>
#include<noise/noiseutils.h>

#include "logger.hpp"

using namespace std;

World::World() {
  generateWorld();
}

void World::generateWorld() {
  Logger::log("Generating world", Logger::DEBUG);
  
  noise::module::Perlin perlin;

  voxels.resize(sizeX);
  for (int i = 0; i < sizeX; i++) {
    voxels[i].resize(sizeY);
    for (int j = 0; j < sizeY; j++) {
      voxels[i][j].resize(sizeZ);
      
      for (int k = 0; k < sizeZ; k++) {
        double height = perlin.GetValue((float)i/sizeX, (float)j/sizeY, (float)k/sizeZ);
        cout << height << endl;
        Voxel::Type type;
        if ( height >= 0 ) {
          type = Voxel::AIR;
        }
        else {
          type = Voxel::GROUND;
        }
        voxels[i][j][k] = new Voxel(type);
      }
    }
  }
  
  Logger::log("Finished generating world", Logger::DEBUG);
}

Voxel* World::getVoxel(int i, int j, int k) {
  return voxels[i][j][k];
}

int World::getSizeX() {
  return sizeX;
}

int World::getSizeY() {
  return sizeY;
}

int World::getSizeZ() {
  return sizeZ;
}
