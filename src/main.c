#include "../include/solid.h"
#include "../include/wire.h"

#include <stdbool.h>
#include <GL/glut.h>

bool wire_mode = false;
GLint posX = 0.0, posY = 0.0;
GLfloat fAspect;

void keyboardFunc(unsigned char key, int x, int y) {
    if (key == 27) { exit(EXIT_SUCCESS); }
}

void specialFunc(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            posY += 1;
            break;
        case GLUT_KEY_LEFT:
            posY -= 1;
            break;
        case GLUT_KEY_UP:
            posX += 1;
            break;
        case GLUT_KEY_DOWN:
            posX -= 1;
            break;

        case GLUT_KEY_F2:
            wire_mode = wire_mode ? false : true;
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(posX %= 360, 1.0, 0.0, 0.0);
    glRotatef(posY %= 360, 0.0, 1.0, 0.0);

    if (!wire_mode) {
        drawSolidSun();
        drawSolidWalls();
        drawSolidRoof();
        drawSolidWindow(-90, -100, 0, -100);
        drawSolidWindow(-90, -100, 0, 100);
        drawSolidWindow(90, 100, 0, -100);
        drawSolidWindow(90, 100, 0, 100);
        drawSolidDoor();
        drawSolidFloor();
    } else {
        drawWireSun();
        drawWireWalls();
        drawWireRoof();
        drawWireWindow(-90, -100, 0, -100);
        drawWireWindow(-90, -100, 0, 100);
        drawWireWindow(90, 100, 0, -100);
        drawWireWindow(90, 100, 0, 100);
        drawWireDoor();
        drawWireFloor();
    }
    glPopMatrix();

    glFlush();
}

void view_parameters() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, fAspect, 1, 3000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 1000.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void reshapeFunc(GLsizei w, GLsizei h) {
    if (h == 0) { h = 1; }

    glViewport(0, 0, w, h);

    fAspect = (GLfloat) w / (GLfloat) h;

    view_parameters();
}

void init() {
    GLfloat ambient_light[4] = {0.5, 0.5, 0.5, 1.0};
    GLfloat diffuse_light[4] = {0.7, 0.7, 0.7, 1.0};
    GLfloat specular_light[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specularity[4] = {0.1, 0.1, 0.1, 1.0};

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE_ARB);
}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutCreateWindow("Casa 3D");
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboardFunc);
    glutReshapeFunc(reshapeFunc);
    glutSpecialFunc(specialFunc);
    init();
    glutMainLoop();
}