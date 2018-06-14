#include<stdlib.h>
#include"glut.h"
void display(void)
{
	static GLubyte frontIndices[] = { 4,5,6,7 };
	static GLubyte rightIndices[] = { 1,2,6,5 };
	static GLubyte bottomIndices[] = { 0,1,5,4 };
	static GLubyte backIndices[] = { 0,3,2,1 };
	static GLubyte leftIndices[] = { 0,4,7,3 };
	static GLubyte topIndices[] = { 2,3,7,6 };
	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(1, 0, 0);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, frontIndices);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, rightIndices);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, bottomIndices);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, backIndices);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, leftIndices);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, topIndices);
	//glDisableClientState(GL_VERTEX_ARRAY);
	//glFlush();
}
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glOrtho(0, 400, 0, 400, -100, 100);
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 300);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Hello");

	init();
	glutDisplayFunc(display);
	glutMainLoop();

}