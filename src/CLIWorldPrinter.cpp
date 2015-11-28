#include "CLIWorldPrinter.hpp"

#include<iostream>

CLIWorldPrinter::CLIWorldPrinter(World* newWorld)
  : world(newWorld) {

}

void CLIWorldPrinter::printWorld(int level) {
  for (int j = 0; j < world->getSizeY(); j++) {
    for (int i = 0; i < world->getSizeX(); i++) {
      Voxel* v = world->getVoxel(i, j, level);

      if (v->getType() == Voxel::STONE) {
        cout << "#";
      }
      else if (v->getType() == Voxel::AIR) {
        cout << " ";
      }
      else if (v->getType() == Voxel::WATER) {
        cout << ".";
      }
    }
    cout << endl;
  }
}
