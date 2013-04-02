/* 
 * File:   Render.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

#include "Render.h"

RenderCircles::RenderCircles() {

    point[0]._x = scale(270);
    point[1]._y = scale(270);
    point[2]._z = scale(270);
    point[3]._x = scale(-120);
    point[3]._z = scale(0);
    point[3]._y = scale(-340);
    point[4] = point[3];
    point[4]._y = scale(-360);
    point[5] = point[3];
    point[5]._y = scale(-380);

    strcpy(strings[0], "X");
    strcpy(strings[1], "Y");
    strcpy(strings[2], "Z");
    strcpy(strings[3], "CARTESIAN");
    strcpy(strings[4], "POLAR");
    strcpy(strings[5], "INTEGER");

    end = leftButtonMouse = rightButtonMouse = false;
    angleX = angleY = angleZ = 0;

    posMouseX = posMouseY = 0;
    value = 150;
}

/*
 * Metodo para desenhar na tela
 */
void RenderCircles::display() {

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

#ifdef _3D_

    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    vertex();
#else    
    grid();
#endif

    updateCircleDraw();
    letters();
    glutSwapBuffers();
}

void RenderCircles::updateCircleDraw() {

    if (value < 250 && !end) {
        drawInterest(value);
        value++;

        if (value == 250) {
            value--;
            end = true;
        }
    } else {
        if (value >= 0 && end) {
            drawInterest(value);
            value--;
            value--;
            if (value == -1) {
                value++;
                end = false;
            }
        }
    }
}

void RenderCircles::letters() {
    for (GLint i = 0; i < NUM_MAX_INFORMATION/2; i++) {
        printstring(strings[i], point[i], i);
    }
}

void RenderCircles::vertex() {

    glBegin(GL_LINES);

    //x
    glColor3f(0, 0, 1);
    glVertex3f(-1, 0, 0);
    glVertex3f(1, 0, 0);
    //y
    glColor3f(0, 1, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0, 1, 0);
    //z
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, -1);
    glVertex3f(0, 0, 1);

    glEnd();

    return;
}

/*
 * funcao que desenha uma malha na tela
 */
void RenderCircles::grid() {

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);

    /*
     * Desenha uma grade para melhor visualização dos
     * pontos na tela
     */
    for (GLint i = -250; i <= 250; i += 5) {
        GLfloat point = scale(i);
        glVertex2f(point, -1);
        glVertex2f(point, 1);
        glVertex2f(-1, point);
        glVertex2f(1, point);
    }

    glEnd();

    return;
}

void RenderCircles::drawInterest(GLint value) {

    cartesian.initializeRadiusAndX(radius2Draw.sizeCartesian[value]);
    polar.initializeRadiusAndX(radius2Draw.sizeCartesian[value]);
    mid.initializeRadiusAndX(radius2Draw.sizeCartesian[value]);

    cartesian.work();
    polar.work();
    mid.work();
}

void RenderCircles::handleKeyPress(unsigned char key, GLint x, GLint y) {
    switch (key) {
        case 27:
        case 'Q':
        case 'q':
            mid.callShowStatistic();
            exit(0);
            break;
    }
}

void RenderCircles::handleMouse(GLint button, GLint state, GLint x, GLint y) {

    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            posMouseX = x;
            posMouseY = y;
            leftButtonMouse = true;
        }

    } else {
        if (button == GLUT_LEFT_BUTTON)
            leftButtonMouse = false;
    }
}

void RenderCircles::handleMouseMotion(GLint x, GLint y) {

    GLfloat newX = posMouseX - x;
    GLfloat newY = posMouseY - y;

    posMouseY = y;
    posMouseX = x;
    if (leftButtonMouse) {

        if (newX < 0) {
            angleY = (angleY - 1);
        } else {
            if (newX > 0) {
                angleY = (angleY + 1);
            }
        }

        if (newY < 0) {
            angleZ = (angleZ - 1);
        } else {
            if (newY > 0) {
                angleZ = (angleZ + 1);
            }
        }
    }
}