#include "world.hpp"

#include<iostream>
#include<random>
#include<noise/noise.h>
#include<noise/noiseutils.h>

#include "logger.hpp"

using namespace std;

World::World(unsigned int x, unsigned int y, unsigned int z, unsigned int wl) 
  : sizeX(x), sizeY(y), sizeZ(z), waterLevel(wl)
{
  generateWorld();
}

void World::generateWorld() {
  Logger::log("Generating world", Logger::DEBUG);
  
  noise::module::Perlin perlin;

  voxels.resize(sizeX);
  for (uint i = 0; i < sizeX; i++) {
    voxels[i].resize(sizeY);
    for (uint j = 0; j < sizeY; j++) {
      voxels[i][j].resize(sizeZ);
      
      for (uint k = 0; k < sizeZ; k++) {
        double perlinValue = perlin.GetValue((float)i/sizeX, (float)j/sizeY, (float)k/sizeZ);
        Voxel::Type type;
        if ( perlinValue >= 0 ) {
          if (k > waterLevel) {
            type = Voxel::AIR;
          }
          else {
            type = Voxel::WATER;
          }
        }
        else {
          type = Voxel::STONE;
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
