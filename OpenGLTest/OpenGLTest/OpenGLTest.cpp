// OpenGLTest.cpp: 主项目文件。

#include "stdafx.h"
#include<stdlib.h>
#include"glut.h"
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1.0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0);
	glVertex3f(0.75, 0.25, 0);
	glVertex3f(0.75, 0.75, 0);
	glVertex3f(0.25, 0.75, 0);
	glEnd();
	glFlush();
}
void init()
{
	glClearColor(0.0, 0.0, 0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(100, 100);
	glutCreateWindow("Hello");

	init();
	glutDisplayFunc(display);
	glutMainLoop();

}