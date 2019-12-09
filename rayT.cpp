#include <GL/glew.h>
#include <GL/glut.h>

#include "constant.h"
#include "ray.h"
#include "render.h"
#include "scene.h"



//----------------------------VARIABLES----------------------------------------

static mat4  mv;


// model
static GLuint program;
static GLuint  ModelView, projection;
static mat4  model_view;



//----------------------------KEYBOARD-------------------------------------------

void scene_keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 033: // Escape Key
	case '1':
		//clean();
		printf("Printing Scence 1..\n");
		scene1();
		break;
	case '2':
		//clean();
		printf("Printing Scence 2..\n");
		scene2();
		break;
	case '3':
		//clean();
		printf("Printing Scence 3..\n");
		scene3();
		break;
	case '4':
		//clean();
		printf("Printing Scence 4..\n");
		scene4();
		break;
	}
}







// initialize display arrays
void init()
{
	//vertexes();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(400, 20);
	glutInitWindowSize(W_Width, W_Height);
	glutCreateWindow("Tetris Game");

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, W_Width / W_Height, 0, -100);

}




int main(int argc, char** argv)
{


	glutInit(&argc, argv);

	init();

	//glutDisplayFunc(display);
	glutKeyboardFunc(scene_keyboard);
	//glutIdleFunc(display);
	glutMainLoop();

	return 0;
}
