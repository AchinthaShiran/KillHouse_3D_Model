#include<iostream>
#include<GL/glut.h>
#include "controls.h"

 GLfloat camY = 0.0f;
 GLfloat camX = 0.0f;
 GLfloat camZ = 0.0f;

 GLfloat rotX = 0.0f;
 GLfloat rotY = 0.0f;
 GLfloat rotZ = 0.0f;

 GLfloat moveX = 0.0f;
 GLfloat moveY = 0.0f;
 GLfloat moveZ = 0.0f;

 GLfloat lightX = 0.0f;
 GLfloat lightY = 0.0f;
 GLfloat lightZ = 0.0f;



 void keyboardSpecial(int key, int x, int y) {
	 if (key == GLUT_KEY_UP)
		 camY += 0.5;

	 if (key == GLUT_KEY_DOWN)
		 camY -= 0.5;

	 if (key == GLUT_KEY_LEFT)
		 camZ += 0.5;

	 if (key == GLUT_KEY_RIGHT)
		 camZ -= 0.5;

	 if (key == '+') {
		 camX += 0.5;
	 }
	 if (key == '-') {
		 camX -= 0.5;
	 }
	 glutPostRedisplay();
 }

void keyboard(unsigned char key, int x, int y) {
	
	//light
	if (key == 'S') {
		lightY += 0.1;
	}
	if (key == 'W') {
		lightY -= 0.1;
	}
	if (key == 'H') {
		lightX += 0.1;
	}
	if (key == 'G') {
		lightX -= 0.1;
	}
	if (key == 'A') {
		lightZ += 0.1;
	}
	if (key == 'D') {
		lightZ -= 0.1;
	}

	
	//move
	if (key == 's') {
		moveY += 0.5;
	}
	if (key == 'w') {
		moveY-= 0.5;
	}
	if (key == 'h') {
		moveX += 0.5;
	}
	if (key == 'g') {
		moveX -= 0.5;
	}
	if (key == 'a') {
		moveZ += 0.5;
	}
	if (key == 'd') {
		moveZ -= 0.5;
	}

	//rotate
	if (key == '[') {
		rotX += 2.0;
	}
	if (key == ']') {
		rotX -= 2.0;
	}
	if (key == 'j') {
		rotY += 2.0;
	}
	if (key == 'l') {
		rotY -= 2.0;
	}
	if (key == 'i') {
		rotZ += 2.0;
	}
	if (key == 'k') {
		rotZ -= 2.0;
	}



	if (key == ')')
		glDisable(GL_LIGHT0);
	if (key == '0')
		glEnable(GL_LIGHT0);
	if (key == '!')
		glDisable(GL_LIGHT1);
	if (key == '1')
		glEnable(GL_LIGHT1);
	if (key == '@')
		glDisable(GL_LIGHT2);
	if (key == '2') 
		glEnable(GL_LIGHT2);
	if (key == '#')
		glDisable(GL_LIGHT3);
	if (key == '3')
		glEnable(GL_LIGHT3);
	if (key == '$')
		glDisable(GL_LIGHT4);
	if (key == '4')
		glEnable(GL_LIGHT4);
	if (key == '%')
		glDisable(GL_LIGHT5);
	if (key == '5')
		glEnable(GL_LIGHT5);
	if (key == '^')
		glDisable(GL_LIGHT6);
	if (key == '6')
		glEnable(GL_LIGHT6);
	if (key == '&')
		glDisable(GL_LIGHT7);
	if (key == '7')
		glEnable(GL_LIGHT7);


	glutPostRedisplay();
}