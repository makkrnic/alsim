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
  static std::vector<Point> pointsXY;
  static std::vector<Point> pointsXZ;
  static std::vector<Point> pointsYZ;

  static GLint windowXY;
  static GLint windowXZ;
  static GLint windowYZ;

  static unsigned int currentXIntersect;
  static unsigned int currentYIntersect;
  static unsigned int currentZIntersect;
  
  static void displayXY();
  static void displayXZ();
  static void displayYZ();
  static void displayRenderPlane(std::vector<Point>& points);
  static void keyboard(unsigned char key, int x, int y);
};
