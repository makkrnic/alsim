#pragma once

class Voxel {
public:
  enum Type {
    AIR,
    STONE,
    WATER,
  };

  Voxel();
  Voxel(Type type);

  Type getType();
  void setType(Type type);

private:
  Type type;
};
