#include "GLWorldDisplay2D.hpp"

#include "logger.hpp"

#include<iostream>
#include<sstream>

World* GLWorldDisplay2D::world;
std::vector<Point> GLWorldDisplay2D::pointsXY;
std::vector<Point> GLWorldDisplay2D::pointsXZ;
std::vector<Point> GLWorldDisplay2D::pointsYZ;

unsigned int GLWorldDisplay2D::currentXIntersect = 0;
unsigned int GLWorldDisplay2D::currentYIntersect = 0;
unsigned int GLWorldDisplay2D::currentZIntersect = 0;

GLint GLWorldDisplay2D::windowXY;
GLint GLWorldDisplay2D::windowXZ;
GLint GLWorldDisplay2D::windowYZ;

void GLWorldDisplay2D::setWorld(World* newWorld) {
  GLWorldDisplay2D::world = newWorld;
}

void GLWorldDisplay2D::displayWorld(int *argcp, char ** argv) {
  glutInit(argcp, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  
  glutInitWindowPosition(540, 380);
  windowXY = glutCreateWindow("Points XY");
  glutKeyboardUpFunc(GLWorldDisplay2D::keyboard);
  glutDisplayFunc(GLWorldDisplay2D::displayXY);
  
  glutInitWindowPosition(540, 760);
  windowXZ = glutCreateWindow("Points XZ");
  glutKeyboardUpFunc(GLWorldDisplay2D::keyboard);
  glutDisplayFunc(GLWorldDisplay2D::displayXZ);

  glutInitWindowPosition(880, 380);
  windowYZ = glutCreateWindow("Points YZ");
  glutKeyboardUpFunc(GLWorldDisplay2D::keyboard);
  glutDisplayFunc(GLWorldDisplay2D::displayYZ);

  glutMainLoop();
}

void GLWorldDisplay2D::displayXY() {
  unsigned int sizeX = world->getSizeX();
  unsigned int sizeY = world->getSizeY();

  pointsXY.clear();
  for (unsigned int j = 0; j < sizeY; j++) {
    for (unsigned int i = 0; i < sizeX; i++) {
      Voxel* v = world->getVoxel(i, j, GLWorldDisplay2D::currentZIntersect);
      Point p;
      p.x = -50 + (float)i/sizeX * 100;
      p.y = -50 + (float)j/sizeY * 100;

      if (v->getType() == Voxel::STONE) {
        p.r = 0;
        p.g = 0;
        p.b = 0;
        p.a = 255;
      }
      else if (v->getType() == Voxel::AIR) {
        p.r = 255;
        p.g = 255;
        p.b = 255;
        p.a = 255;
      }
      else if (v->getType() == Voxel::WATER) {
        p.r = 0;
        p.g = 0;
        p.b = 255;
        p.a = 255;
      }

      GLWorldDisplay2D::pointsXY.push_back(p);
    }
  }

  displayRenderPlane(pointsXY);
}
void GLWorldDisplay2D::displayXZ() {
  unsigned int sizeX = world->getSizeX();
  unsigned int sizeZ = world->getSizeZ();

  pointsXZ.clear();
  for (unsigned int i = 0; i < sizeX; i++) {
    for (unsigned int k = 0; k < sizeZ; k++) {
      Voxel* v = world->getVoxel(i, GLWorldDisplay2D::currentYIntersect, k);
      Point p;
      p.x = -50 + (float)i/sizeX * 100;
      p.y = -50 + (float)k/sizeZ * 100;

      if (v->getType() == Voxel::STONE) {
        p.r = 0;
        p.g = 0;
        p.b = 0;
        p.a = 255;
      }
      else if (v->getType() == Voxel::AIR) {
        p.r = 255;
        p.g = 255;
        p.b = 255;
        p.a = 255;
      }
      else if (v->getType() == Voxel::WATER) {
        p.r = 0;
        p.g = 0;
        p.b = 255;
        p.a = 255;
      }

      GLWorldDisplay2D::pointsXZ.push_back(p);
    }
  }

  displayRenderPlane(pointsXZ);
}

void GLWorldDisplay2D::displayYZ() {
  unsigned int sizeY = world->getSizeY();
  unsigned int sizeZ = world->getSizeZ();

  pointsYZ.clear();
  for (unsigned int j = 0; j < sizeY; j++) {
    for (unsigned int k = 0; k < sizeZ; k++) {
      Voxel* v = world->getVoxel(currentXIntersect, j, k);
      Point p;
      p.x = -50 + (float)j/sizeY * 100;
      p.y = -50 + (float)k/sizeZ * 100;

      if (v->getType() == Voxel::STONE) {
        p.r = 0;
        p.g = 0;
        p.b = 0;
        p.a = 255;
      }
      else if (v->getType() == Voxel::AIR) {
        p.r = 255;
        p.g = 255;
        p.b = 255;
        p.a = 255;
      }
      else if (v->getType() == Voxel::WATER) {
        p.r = 0;
        p.g = 0;
        p.b = 255;
        p.a = 255;
      }

      GLWorldDisplay2D::pointsYZ.push_back(p);
    }
  }

  displayRenderPlane(pointsYZ);
}

void GLWorldDisplay2D::displayRenderPlane(std::vector<Point>& points) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50, 50, -50, 50, -1, 1);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glColor3ub(255, 255, 255);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glVertexPointer(2, GL_FLOAT, sizeof(Point), &points[0].x);
  glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(Point), &points[0].r);
  glPointSize(10.0);
  glDrawArrays(GL_POINTS, 0, points.size());
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);

  glFlush();
  glutSwapBuffers();
}

void GLWorldDisplay2D::keyboard(unsigned char key, int x, int y) {
  std::stringstream windowTitle;
  
  switch(key) {
    case '7':
      glutSetWindow(windowXY);
      if (currentZIntersect < world->getSizeZ() - 1) {
        currentZIntersect++;
      }
      windowTitle << "XY: " << currentZIntersect + 1 << "/" << world->getSizeZ();
      break;

    case '4':
      glutSetWindow(windowXY);
      if (currentZIntersect > 0) {
        currentZIntersect--;
      }
      windowTitle << "XY: " << currentZIntersect + 1 << "/" << world->getSizeZ();
      break;
    
    case '8':
      glutSetWindow(windowXZ);
      if (currentYIntersect < world->getSizeY() - 1) {
        currentYIntersect++;
      }
      windowTitle << "XZ: " << currentYIntersect + 1 << "/" << world->getSizeY();
      break;

    case '5':
      glutSetWindow(windowXZ);
      if (currentYIntersect > 0) {
        currentYIntersect--;
      }
      windowTitle << "XZ: " << currentYIntersect + 1 << "/" << world->getSizeY();
      break;
    
    case '9':
      glutSetWindow(windowYZ);
      if (currentXIntersect < world->getSizeX() - 1) {
        currentXIntersect++;
      }
      windowTitle << "YZ: " << currentXIntersect + 1 << "/" << world->getSizeX();
      break;

    case '6':
      glutSetWindow(windowYZ);
      if (currentXIntersect > 0) {
        currentXIntersect--;
      }
      windowTitle << "YZ: " << currentXIntersect + 1 << "/" << world->getSizeX();
      break;
  }

  glutSetWindowTitle(windowTitle.str().c_str());
  glutPostRedisplay();
}
