/* 
 * File:   Render.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

#include "Render.h"
#include "SpaceShip.h"

Render::Render() {

    end = leftButtonMouse = rightButtonMouse = false;
    angleX = angleY = angleZ = 0;

    posMouseX = posMouseY = 0;
    value = 150;
}

void Render::setSpaceShip() {
    static bool flag = false;

    if (!flag) {
        Point3D point(0, 0, -1000);
        space = new SpaceShip(point, 3.0f);

        listOfElements.push_back(space);
        flag = true;
    }
}

/*
 * Metodo para desenhar na tela
 */
void Render::display() {

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawInterest();

    glFlush();
    glutSwapBuffers();
}

void Render::drawInterest() {

    std::vector<Objects *>::iterator it = listOfElements.begin();

    while (it != listOfElements.end()) {
        (*it)->drawObject();
        it++;
    }
}

void Render::doSomethingInTime() {

//    std::vector<Objects*>::iterator it = listOfElements.begin();
//
//    while (it != listOfElements.end()) {
////        (*it)->updateRotation();
//        it++;
//    }

    setSpaceShip();
}

void Render::handleKeyPress(unsigned char key, GLint x, GLint y) {
    space->controlOfSpaceTranslation(key,x,y);
}

void Render::handleKeyPressNumber(int key, GLint x, GLint y) {
    space->controlOfSpaceRotation(key,x,y);
}

void Render::handleMouse(GLint button, GLint state, GLint x, GLint y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_RIGHT_BUTTON) {

            posMouseX = 2 * x - SIDE_SIZE;
            posMouseY = (2 * y - SIDE_SIZE)*-1.0f;


            rightButtonMouse = true;

            int randNumber = 1 + rand() % RANDOM_NUMBER;

            if (randNumber < 5) {

                Point3D point(400,
                        400, -1000);
                //(float) posMouseY / SIDE_SIZE
                Objects *sphere = new Sphere(point, 0.01f);
                listOfElements.push_back(sphere);

            }
        }

    } else {
        if (button == GLUT_LEFT_BUTTON)
            leftButtonMouse = false;
        else {
            if (button == GLUT_RIGHT_BUTTON)
                rightButtonMouse = false;
        }
    }
}

void Render::handleMouseMotion(GLint x, GLint y) {
}