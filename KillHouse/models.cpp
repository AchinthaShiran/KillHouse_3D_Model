#include<iostream>
#include<GL/glut.h>
#include "models.h"


extern unsigned int texture[2];

void wall(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h) {
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	//TOP
	glTexCoord2f(0.0,0.0); glVertex3f(x, y + h, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x, y + h, z + l);
	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x + w, y + h, z);
	glEnd();

	//BOTTOM
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y, z);
	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x, y, z + l);
	glEnd();
	// FRONT
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, z + l);
	glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y, z + l);
	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x, y + h, z + l);
	glEnd();



	//// BACK
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(x, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x, y + h, z);
	glTexCoord2f(0.0, 0.0); glVertex3f(x + w, y + h, z);
	glTexCoord2f(0.0, 1.0); glVertex3f(x + w, y, z);
	glEnd();



	// LEFT
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x, y, z + l);
	glTexCoord2f(1.0, 1.0); glVertex3f(x, y + h, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x, y + h, z);
	glEnd();
	//RIGHT
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y + h, z);
	glTexCoord2f(0.0, 0.0); glVertex3f(x + w, y + h, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x + w, y, z + l);
	glEnd();
}

void wallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len, GLfloat height) {
	wall(x, y, z, 1, len, height);
}

void normalWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, 1, len, 5);
}

void shortWallX_1(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, 1, len, 1);
}



void shortWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, 1, len, 2);
}


void wallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len, GLfloat height) {
	wall(x, y, z, 1, len, height);
}

void normalWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, len, 1, 5);
}

void shortWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, len, 1, 1);
}

void wallFlat(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w) {
	wall(x, y, z, w, l, 1);
}


void hut(GLfloat x, GLfloat y, GLfloat z) {
	glTranslatef(x, y, z);
	
	//front
	normalWallX(0, 0, 0, 4);
	shortWallX_1(0, 0, 4, 5);
	shortWallX_1(0, 4, 4, 5);
	normalWallX(0, 0, 9, 2);
	wallX(0, 1, 6, 1, 3);

	//side
	normalWallY(0, 0, 0, 8);
	normalWallY(0, 0, 10, 8);


	//top
	wallFlat(0, 5, 0, 11, 4);
	wallFlat(4, 5, 4, 7, 4);
	wallFlat(4, 5, 0, 1, 4);
	wallX(0, 6, 0, 11, 1);

	//back
	normalWallX(7, 0, 9, 1);
	normalWallX(7, 0, 4, 3);
	shortWallX_1(7, 4, 7, 2);
	
}

void hutOne(GLfloat x, GLfloat y, GLfloat z) {
	hut(x, y, z);
	shortWallX(0, 0, -5, 5);
	shortWallX(0, 0, 10, 4);

}