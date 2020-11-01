#include "../include/solid.h"

#include <GL/glut.h>

void draw_solid_house_walls() {
    glColor3f(0.7f, 0.7f, 0.7f);
        glPushMatrix();
            glScalef(2.0, 2.0, 4.0);
                glutSolidCube(1);
        glPopMatrix();

    glColor3f(0.4f, 0.4f, 0.4f);
        glPushMatrix();
            glTranslatef(0, 1, 1);
                glBegin(GL_TRIANGLES);
                    glVertex3f(-1, 0, 1);
                    glVertex3f(1, 0, 1);
                    glVertex3f(0, 1, 1);
                glEnd();
        glPopMatrix();

    glColor3f(0.55f, 0.55f, 0.55f);
        glPushMatrix();
            glTranslatef(0, 1, -3);
                glBegin(GL_TRIANGLES);
                    glVertex3f(-1, 0, 1);
                    glVertex3f(1, 0, 1);
                    glVertex3f(0, 1, 1);
                glEnd();
        glPopMatrix();
}

void draw_solid_roof() {
    glPushMatrix();
        glColor3f(0.6f, 0.0f, 0.0f);
            glTranslatef(-0.6, 1.4, 0);
            glRotatef(45, 0, 0, 1);
            glScalef(1.8, 0.1, 4.5);
                glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.6f, 0.0f, 0.0f);
            glTranslatef(0.6, 1.4, 0);
            glRotatef(135, 0, 0, 1);
            glScalef(1.8, 0.1, 4.5);
                glutSolidCube(1);
    glPopMatrix();
}

void draw_solid_door() {
    glPushMatrix();
        glTranslatef(0, -0.23, 2);

            // door
            glPushMatrix();
                glColor3ub(34, 22, 11);
                    glScalef(0.8, 1.34, 0.1);
                        glutSolidCube(1);
            glPopMatrix();

            // right frame
            glPushMatrix();
                glColor3ub(101, 67, 33);
                    glTranslatef(0.45, 0, 0);
                    glScalef(0.1, 1.54, 0.2);
                        glutSolidCube(1);
            glPopMatrix();

            // left frame
            glPushMatrix();
                glColor3ub(101, 67, 33);
                    glTranslatef(-0.45, 0, 0);
                    glScalef(0.1, 1.54, 0.2);
                        glutSolidCube(1);
            glPopMatrix();

            // upper frame
            glPushMatrix();
                glColor3ub(101, 67, 33);
                    glTranslatef(0, 0.72, 0);
                    glScalef(0.8, 0.1, 0.2);
                        glutSolidCube(1);
            glPopMatrix();

            // lower step
            glPushMatrix();
                glColor3ub(101, 67, 33);
                    glTranslatef(0, -0.72, 0);
                    glScalef(0.8, 0.1, 0.4);
                        glutSolidCube(1);
            glPopMatrix();

            // door knob
            glPushMatrix();
                glColor3ub(255, 255, 0);
                glTranslatef(0.3, 0, 0.05);
                    glutSolidSphere(0.05, 10, 10);
            glPopMatrix();
    glPopMatrix();
}

void draw_solid_window(double angle, double x, double y, double z) {
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotated(angle, 0, 1, 0);

        // window
        glPushMatrix();
            glColor3ub(0, 0, 0);
                glScalef(0.67, 1, 0.1);
                    glutSolidCube(1);
        glPopMatrix();

        // right frame
        glPushMatrix();
            glColor3ub(101, 67, 33);
                glTranslatef(0.385, 0, 0);
                glScalef(0.1, 1, 0.2);
                    glutSolidCube(1);
        glPopMatrix();

        // left frame
        glPushMatrix();
            glColor3ub(101, 67, 33);
                glTranslatef(-0.385, 0, 0);
                glScalef(0.1, 1, 0.2);
                    glutSolidCube(1);
        glPopMatrix();

        // upper frame
        glPushMatrix();
            glColor3ub(101, 67, 33);
                glTranslatef(0, 0.55, 0);
                glScalef(0.87, 0.1, 0.2);
                    glutSolidCube(1);
        glPopMatrix();

        // lower frame
        glPushMatrix();
            glColor3ub(101, 67, 33);
                glTranslatef(0, -0.55, 0);
                glScalef(0.87, 0.1, 0.4);
                    glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
}

void draw_solid_floor() {
    glPushMatrix();
        glColor3f(0, 0.2, 0);
            glTranslatef(0, -1.05, 0);
            glScalef(4, 0.1, 6);
                glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3ub(34, 22, 11);
            glTranslatef(0, -1.35, 0);
            glScalef(4, 0.5, 6);
                glutSolidCube(1);
    glPopMatrix();
}

void draw_solid_sun() {
    GLfloat light_position[4] = {-4, 5, -5, 1.0};
    GLfloat light_emission[4] = {0.5, 0.5, 0.5, 0.0};
    GLfloat light_emission_reset[4] = {0.0, 0.0, 0.0, 0.0};

    glPushMatrix();
        glColor3f(1, 1, 0);
            glTranslatef(-4, 5, -5);
                glMaterialfv(GL_FRONT, GL_EMISSION, light_emission);
                glutSolidSphere(1, 10, 10);
                glLightfv(GL_LIGHT0, GL_POSITION, light_position);
                glMaterialfv(GL_FRONT, GL_EMISSION, light_emission_reset);
    glPopMatrix();

}