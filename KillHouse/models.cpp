#include<iostream>
#include<GL/glut.h>
#include "models.h"

void wall(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h) {
	glBegin(GL_QUADS);

	// BACK
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(x, y, z);
	glVertex3f(x, y + h, z);
	glVertex3f(x + w, y + h, z);
	glVertex3f(x + w, y, z);
	glEnd();

	// FRONT
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.5);
	glVertex3f(x, y, z + l);
	glVertex3f(x + w, y, z + l);
	glVertex3f(x + w, y + h, z + l);
	glVertex3f(x, y + h, z + l);
	glEnd();

	// LEFT
	glBegin(GL_QUADS);
	glColor3f(0.5, 1.0, 0.5);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + l);
	glVertex3f(x, y + h, z + l);
	glVertex3f(x, y + h, z);
	glEnd();

	//RIGHT
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 1.0);
	glVertex3f(x + w, y, z);
	glVertex3f(x + w, y, z + l);
	glVertex3f(x + w, y + h, z + l);
	glVertex3f(x + w, y + h, z);
	glEnd();

	//TOP
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.5);
	glVertex3f(x, y + h, z);
	glVertex3f(x + w, y + h, z);
	glVertex3f(x + w, y + h, z + l);
	glVertex3f(x, y + h, z + l);
	glEnd();

	//BOTTOM
	glBegin(GL_QUADS);
	glColor3f(0.5, 1.0, 1.0);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + l);
	glVertex3f(x + w, y, z + l);
	glVertex3f(x + w, y, z);
	glEnd();
}