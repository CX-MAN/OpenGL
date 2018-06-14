// OpenGLTest.cpp: 主项目文件。

#include "stdafx.h"
#include<stdlib.h>
#include"glut.h"
#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES);\
glVertex2f((x1),(y1));glVertex2f((x2),(y2));glEnd();
void display(void)
{
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0101);
	drawOneLine(50.0,125.0,150,125.0);
	glLineStipple(1,0x00ff);
	drawOneLine(150,125,250,125);
	glLineStipple(1,0x1c47);
	drawOneLine(250, 125, 350, 125);
	glDisable(GL_LINE_STIPPLE);
	glFlush();
}
void init()
{
	glClearColor(0.0, 0.0, 0.0,0.0);
	glShadeModel(GL_FLAT);
	glOrtho(0, 400, 0, 400, -1, 1);
}
void reshape(int w,int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 300);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Hello");

	init();
	glutDisplayFunc(display);
	glutMainLoop();

}