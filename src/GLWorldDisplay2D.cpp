#include "GLWorldDisplay2D.hpp"

World* GLWorldDisplay2D::world;
std::vector<Point> GLWorldDisplay2D::points;

void GLWorldDisplay2D::setWorld(World* newWorld) {
  GLWorldDisplay2D::world = newWorld;
}

void GLWorldDisplay2D::displayWorld(int *argcp, char ** argv) {
  glutInit(argcp, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  
  glutInitWindowPosition(640, 480);
  glutCreateWindow("Points");

  glutDisplayFunc(GLWorldDisplay2D::display);

  glutMainLoop();
}

void GLWorldDisplay2D::display() {
  unsigned int sizeX = world->getSizeX();
  unsigned int sizeY = world->getSizeY();

  points.clear();
  for (unsigned int j = 0; j < sizeY; j++) {
    for (unsigned int i = 0; i < sizeX; i++) {
      Voxel* v = world->getVoxel(i, j, 0);
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

      GLWorldDisplay2D::points.push_back(p);
    }
  }

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
  glPointSize(3.0);
  glDrawArrays(GL_POINTS, 0, points.size());
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);

  glFlush();
  glutSwapBuffers();
}
