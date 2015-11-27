#include "voxel.hpp"

Voxel::Voxel()
  : type(AIR) {

}

Voxel::Voxel(Type newType)
  : type(newType) {

}

Voxel::Type Voxel::getType() {
  return type;
}
