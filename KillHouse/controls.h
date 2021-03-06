#pragma once

extern GLfloat camY;
extern GLfloat camX;
extern GLfloat camZ;

extern GLfloat rotX;
extern GLfloat rotY;
extern GLfloat rotZ;

extern GLfloat moveX;
extern GLfloat moveY;
extern GLfloat moveZ;

extern GLfloat lightX;
extern GLfloat lightY;
extern GLfloat lightZ;

void keyboardSpecial(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);