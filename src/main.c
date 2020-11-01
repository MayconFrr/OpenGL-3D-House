#include "../include/solid.h"
#include "../include/wire.h"

#include <GL/glut.h>
#include <stdbool.h>

bool developer_mode = false;
int posX = 0, posY = 0;
GLfloat fAspect;

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
            developer_mode = developer_mode ? false : true;
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y) {
    if (key == 27) {
        exit(EXIT_SUCCESS);
    }
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(posX %= 360, 1.0, 0.0, 0.0);
    glRotatef(posY %= 360, 0.0, 1.0, 0.0);

    if (developer_mode) {
        draw_wire_sun();
        draw_wire_house_walls();
        draw_wire_roof();
        draw_wire_door();
        draw_wire_window(90, -1, 0, 1);
        draw_wire_window(90, -1, 0, -1);
        draw_wire_window(90, 1, 0, 1);
        draw_wire_window(90, 1, 0, -1);
        draw_wire_floor();
    } else {
        draw_solid_sun();
        draw_solid_house_walls();
        draw_solid_roof();
        draw_solid_door();
        draw_solid_window(90, -1, 0, 1);
        draw_solid_window(90, -1, 0, -1);
        draw_solid_window(90, 1, 0, 1);
        draw_solid_window(90, 1, 0, -1);
        draw_solid_floor();
    }

    glPopMatrix();

    glFlush();
}

void view_parameters() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, fAspect, 4, 20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void reshapeFunc(GLsizei w, GLsizei h) {
    if (h == 0) {
        h = 1;
    }

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

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularity);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH);
    glutCreateWindow("Casa 3D");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeFunc);
    glutSpecialFunc(specialFunc);
    glutKeyboardFunc(keyboardFunc);
    init();
    glutMainLoop();
}