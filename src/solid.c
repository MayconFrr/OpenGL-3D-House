#include "../include/solid.h"

#include <GL/glut.h>

void drawSolidSun() {
    GLfloat light_position[4] = {-400, 500, -500, 1.0};
    GLfloat light_emission[4] = {0.6, 0.6, 0.6, 1.0};
    GLfloat light_emission_reset[4] = {0.0, 0.0, 0.0, 0.0};

    glColor3f(1, 1, 0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, light_emission);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glPushMatrix();
    glTranslatef(-400, 500, -500);
    glutSolidSphere(50, 20, 20);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_EMISSION, light_emission_reset);
}

void drawSolidWalls() {
    glColor3f(0.7f, 0.7f, 0.7f);

    glPushMatrix();
    glScalef(2, 2, 4);
    glutSolidCube(100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 100, 0);
    glRotatef(45, 0, 0, 1);
    glScalef(1.4142, 1.4142, 4);
    glutSolidCube(100);
    glPopMatrix();
}

void drawSolidRoof() {
    glColor3f(0.7f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(-50, 150, 0);
    glRotatef(45, 0, 0, 1);
    glScalef(1.8, 0.1, 4.4);
    glTranslatef(-5, 50, 0);
    glutSolidCube(100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, 150, 0);
    glRotatef(-45, 0, 0, 1);
    glScalef(1.8, 0.1, 4.4);
    glTranslatef(5, 50, 0);
    glutSolidCube(100);
    glPopMatrix();
}

void drawSolidWindow(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    glColor3ub(101, 67, 33);

    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(angle, 0, 1, 0);

    // right frame
    glPushMatrix();
    glTranslatef(38.5, 0, 0);
    glScalef(0.1, 1, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    // left frame
    glPushMatrix();
    glTranslatef(-38.5, 0, 0);
    glScalef(0.1, 1, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    // upper frame
    glPushMatrix();
    glTranslatef(0, 55, 0);
    glScalef(0.87, 0.1, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    // lower frame
    glPushMatrix();
    glTranslatef(0, -55, 0);
    glScalef(0.87, 0.1, 0.4);
    glutSolidCube(100);
    glPopMatrix();

    // Window
    glColor3f(0, 0, 0);

    glPushMatrix();
    glScalef(0.67, 1, 0.01);
    glutSolidCube(100);
    glPopMatrix();

    glPopMatrix();
}

void drawSolidDoor() {
    glPushMatrix();
    glTranslatef(0, -23, 200);

    glColor3ub(101, 67, 33);

    // right frame
    glPushMatrix();
    glTranslatef(45, 0, 0);
    glScalef(0.1, 1.54, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    // left frame
    glPushMatrix();
    glTranslatef(-45, 0, 0);
    glScalef(0.1, 1.54, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    // upper frame
    glPushMatrix();
    glTranslatef(0, 72, 0);
    glScalef(0.8, 0.1, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    // lower step
    glPushMatrix();
    glTranslatef(0, -72, 0);
    glScalef(0.8, 0.1, 0.4);
    glutSolidCube(100);
    glPopMatrix();

    // door
    glColor3ub(34, 22, 11);

    glPushMatrix();
    glScalef(0.8, 1.34, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    // door knob
    glColor3ub(255, 255, 0);

    glPushMatrix();
    glTranslatef(30, 0, 5);
    glutSolidSphere(5, 10, 10);
    glPopMatrix();

    glPopMatrix();
}

void drawSolidFloor() {
    glColor3f(0, 0.2, 0);

    glPushMatrix();
    glTranslatef(0, -105, 0);
    glScalef(4, 0.1, 6);
    glutSolidCube(100);
    glPopMatrix();

    glColor3ub(34, 22, 11);

    glPushMatrix();
    glTranslatef(0, -135, 0);
    glScalef(4, 0.5, 6);
    glutSolidCube(100);
    glPopMatrix();
}
