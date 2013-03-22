/* 
 * File:   Render.cpp
 * Author: gilvolpe
 * 
 * Created on March 22, 2013, 5:10 PM
 */

#include "Render.h"

Render::Render(int argc, char **argv) {

    this->sizeX = 500;
    this->sizeY = 500;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glDisable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutInitWindowSize(sizeX, sizeY);
    glutCreateWindow("Primeiro Trabalho de Computação Gráfica");

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyPress);

}

Render::Render(const Render& orig) {
}

Render::~Render() {
}

