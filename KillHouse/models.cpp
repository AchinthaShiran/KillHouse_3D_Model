#include<iostream>
#include<GL/glut.h>
#include "models.h"


extern unsigned int texture[2];

void wall_dead(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h) {
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


void cube(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h) {
	
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glTranslatef(x, y, z);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	//TOP
	glTexCoord2f(0.0, 0.0); glVertex3f(0, h, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, h, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(w , h, 0);
	glEnd();

	//BOTTOM
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(w,0, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(w , 0, l );
	glTexCoord2f(0.0, 1.0); glVertex3f(0,0, l);
	glEnd();


	// FRONT
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, l);
	glTexCoord2f(1.0, 0.0); glVertex3f(w, 0, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, h , l);
	glEnd();



	//// BACK
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, h, 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(w , h, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(w , 0, 0);
	glEnd();



	// LEFT
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, l );
	glTexCoord2f(1.0, 1.0); glVertex3f(0, h, l );
	glTexCoord2f(0.0, 1.0); glVertex3f(0, h , 0);
	glEnd();
	//RIGHT


	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(w , 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(w , h , 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(w , h , l );
	glTexCoord2f(0.0, 1.0); glVertex3f(w, 0, l) ;
	glEnd();


	glPopMatrix();
}


void wallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len, GLfloat height) {
	cube(x, y, z, 1, len, height);

}

void highWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, 1, len, 5);
}

void mediumWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, 1, len, 4);
}

void shortWallX_1(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, 1, len, 1);
}

void lowWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, 1, len, 2);
}


void wallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len, GLfloat height) {
	cube(x, y, z, 1, len, height);
}

void highWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, len, 1, 5);
}

void mediumWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, len, 1, 4);
}

void lowWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, len, 1, 2);
}


void wallFlat(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w) {
	cube(x, y, z, w, l, 1);
}


void container(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 5, 15, 5);
}


void cardBoardWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, len, 0.2, 5);
}
void cardBoardWallX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, 0.2, len, 5);
}
void cardBoardLowY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, len, 0.2, 1);
}
void cardBoardLowX(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, 0.2, len, 1);
}

void towerPole(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 0.3, 0.3, 15);
}

void towerPoleShortX(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 4.3, 0.3, 0.3);
}
void towerPoleShortY(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 0.3, 4.3, 0.3);
}

void towerSideY(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 0.3, 4.3, 2.0);
}

void towerSideX(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 4.3, 0.3, 2.0);
}

void towerSideX_Ladder(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 1.25, 0.3, 2.0);
	cube(x+3.05, y, z, 1.15, 0.3, 2.0);
}


void towerRoof(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 5.2, 5.2, 0.05);
}

void towerFloor(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 4.3, 4.3, 0.1);
}

void ladder(GLfloat x, GLfloat y, GLfloat z) {
	cube(x, y, z, 0.05, 0.05, 10);
	cube(x+1, y, z, 0.05, 0.05,10);

	for (int i = 0; i < 20; i++) {
		cube(x, y+(i/2), z, 1, 0.05, 0.05);
	}

}



void hut() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

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
	
	glDisable(GL_TEXTURE_2D);
}

void hutOne() {
	hut();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	lowWallX(0, 0, -4, 4);
	lowWallX(0, 0, 11, 2);
	glDisable(GL_TEXTURE_2D);

}

void hutTwo() {
	hut();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	mediumWallX(0, 0, -2, 2);
	lowWallX(0, 0, -5, 3);
	mediumWallX(0, 0, -8, 3);

	mediumWallX(1, 0, 11, 2);
	lowWallX(1, 0, 13, 3);
	mediumWallX(1, 0, 16, 3);
	glDisable(GL_TEXTURE_2D);

}

void sideOneWalls() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

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

	glDisable(GL_TEXTURE_2D);

}


void sideOne(GLfloat x, GLfloat y, GLfloat z) {
	glTranslatef(x, y, z);
	hutOne();
	sideOneWalls();

	//container(-20, y, 30);

}

void sideTwoWalls() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

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

	glDisable(GL_TEXTURE_2D);

}

void sideTwo(GLfloat x, GLfloat y, GLfloat z) {
	glTranslatef(x, y, z);
	hutTwo();
	sideTwoWalls();

	container(-20, 0, -23);
}

void cardBoardHouse(GLfloat x, GLfloat y, GLfloat z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	
	cardBoardWallX(0, 0, 0, 3);
	cardBoardLowX(0, 4, 3, 2);
	cardBoardWallX(0, 0, 5, 4);

	cardBoardWallX(10, 0, 0, 5);
	cardBoardLowX(10, 4, 5, 2);
	cardBoardWallX(10, 0, 7, 2);

	cardBoardWallX(20, 0, 0, 3);
	cardBoardLowX(20, 4, 3, 2);
	cardBoardWallX(20, 0, 5, 4);


	cardBoardWallY(0, 0, 0, 20);

	cardBoardWallY(0, 0, 9, 3);
	cardBoardLowY(3, 0, 9, 2);
	cardBoardLowY(3, 4, 9, 2);
	cardBoardWallY(5, 0, 9, 10);
	cardBoardLowY(15, 0, 9, 2);
	cardBoardLowY(15, 4, 9, 2);
	cardBoardWallY(17, 0, 9, 3);


	glPopMatrix();
}

void tower(GLfloat x, GLfloat y, GLfloat z) {
	//legs
	towerPole(0, 0, 0);
	towerPole(4, 0, 0);
	towerPole(0, 0, 4);
	towerPole(4, 0, 4);

	//top frame
	towerPoleShortX(0, 15, 0);
	towerPoleShortY(4, 15, 0);
	towerPoleShortX(0, 15, 4);
	towerPoleShortY(0, 15, 0);

	//bottom frame
	//towerPoleShortX(0, 0, 0);
	towerPoleShortY(4, 0, 0);
	//towerPoleShortX(0, 0, 4);
	towerPoleShortY(0, 0, 0);

	//sides
	towerSideX(0, 10, 0);
	towerSideY(4, 10, 0);
	//towerSideX(0, 10, 4);
	towerSideY(0, 10, 0);
	towerSideX_Ladder(0, 10, 4);

	towerRoof(-0.45, 15.3, -0.45);
	towerFloor(0, 10, 0);
	ladder(1.53, 0, 4.3);
}