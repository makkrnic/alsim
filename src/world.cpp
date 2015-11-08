#include "world.hpp"

#include "logger.hpp"

World::World() {
  generateWorld();
}

void World::generateWorld() {
  Logger::log("Generating world", Logger::DEBUG);
  voxels.resize(100);
  for (int i = 0; i < 100; i++) {
    voxels[i].resize(100);
    for (int j = 0; j < 100; j++) {
      voxels[i][j].resize(1);
      voxels[i][j][0] = new Voxel();
    }
  }
  
  Logger::log("Finished generating world", Logger::DEBUG);
}
