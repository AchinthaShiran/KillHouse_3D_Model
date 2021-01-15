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

void highWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, 1, len, 5);
}

void mediumWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, 1, len, 4);
}

void shortWallX_1(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, 1, len, 1);
}


void lowWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, 1, len, 2);
}






void wallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len, GLfloat height) {
	wall(x, y, z, 1, len, height);
}

void highWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, len, 1, 5);
}

void mediumWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, len, 1, 4);
}


void lowWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	wall(x, y, z, len, 1, 2);
}

void wallFlat(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w) {
	wall(x, y, z, w, l, 1);
}


void hut() {
	//front
	highWallX(0, 0, 0, 4);
	shortWallX_1(0, 0, 4, 5);
	shortWallX_1(0, 4, 4, 5);
	highWallX(0, 0, 9, 2);
	wallX(0, 1, 6, 1, 3);

	//side
	highWallY(0, 0, 0, 8);
	highWallY(0, 0, 10, 8);


	//top
	wallFlat(0, 5, 0, 11, 4);
	wallFlat(4, 5, 4, 7, 4);
	wallFlat(4, 5, 0, 1, 4);
	wallX(0, 6, 0, 11, 1);

	//back
	highWallX(7, 0, 9, 1);
	highWallX(7, 0, 4, 3);
	shortWallX_1(7, 4, 7, 2);
	
}

void hutOne() {
	hut();
	lowWallX(0, 0, -4, 4);
	lowWallX(0, 0, 11, 2);

}

void hutTwo() {
	hut();
	mediumWallX(0, 0, -2, 2);
	lowWallX(0, 0, -5, 3);
	mediumWallX(0, 0, -8, 3);

	mediumWallX(1, 0, 11, 2);
	lowWallX(1, 0, 13, 3);
	mediumWallX(1, 0, 16, 3);
}

void sideOneWalls() {
	//w1
	highWallX(10, 0, -20, 16);
	//w2
	highWallX(10, 0, 20, 13);
	//w3
	mediumWallX(-1, 0, 18, 3);
	lowWallX(-1, 0, 21, 4);
	mediumWallX(-1, 0, 25, 8);
	//w4
	highWallX(-4, 0, -20, 10);
	//w5
	lowWallX(-6, 0, 14, 3);
	lowWallY(-6, 0, 13, 4);
	//w3
	mediumWallY(-13, 0, 28, 7);
}


void sideOne(GLfloat x, GLfloat y, GLfloat z) {
	glTranslatef(x, y, z);
	hutOne();
	sideOneWalls();

}

void sideTwoWalls() {
	//w1
	mediumWallX(0, 0, -17, 4);
	lowWallX(0, 0, -20, 3);
	mediumWallX(0, 0, -23, 3);

	//w2
	highWallX(10, 0, -23, 18);

	//w3
	highWallX(10, 0, 17, 14);


	//w4
	mediumWallY(-1, 0, 23, 6);
	mediumWallX(2, 0, 24, 2);
	lowWallX(2, 0, 26, 3);
	mediumWallX(2, 0, 29, 2);

	//w5
	lowWallX(-7, 0, 3, 6);
	lowWallY(-6, 0, 5, 2);

	//w6
	mediumWallY(-10, 0, -17, 6);
	mediumWallX(-7, 0, -16, 7);
}

void sideTwo(GLfloat x, GLfloat y, GLfloat z) {
	glTranslatef(x, y, z);
	hutTwo();
	sideTwoWalls();

}