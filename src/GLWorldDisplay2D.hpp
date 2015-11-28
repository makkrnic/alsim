#pragma once

#include<GL/glut.h>
#include<vector>

#include "world.hpp"

struct Point {
  float x, y;
  unsigned char r, g, b, a;
};

class GLWorldDisplay2D {
public:
  static void setWorld(World* world);
  static void displayWorld(int *argc, char ** argv);

private:
  static World* world;
  static void display();
  static std::vector<Point> points;
};
