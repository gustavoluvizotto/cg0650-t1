/* 
 * File:   Render.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

#include "Render.h"
#include <GL/glut.h>

Render::Render(const Render& orig) {
}

Render::~Render() {
}

/*
 * Construtor para definir tamanho da tela, modo de apresentacao, cor do fundo,
 * e desenho na tela
 * 
 */
Render::Render(int argc, char **argv) {

    this->sizeX = 500;
    this->sizeY = 500;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // desabilita profundidade (coordenada z)
    glDisable(GL_DEPTH_TEST);      
    // cor de fundo da janela: 1,1,1,1 = branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);        

    glutInitWindowSize(sizeX, sizeY);           // definindo o tamanho da tela
    glutCreateWindow("Primeiro Trabalho de Computacao Grafica");

    glutDisplayFunc(drawScene);                 // metodo que faz os desenhos
    glutKeyboardFunc(handleKeyPress);

}

/*
 * Metodo para desenhar na tela
 */
void Render::drawScene() {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex2f(0, 0);
        glVertex2f(1, 1);
    glEnd();
        
    glutSwapBuffers();
}

void Render::handleKeyPress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
                exit(0);
        break;
    }
}

/*
 * Metodo para deixar o programa em loop
*/
void Render::start() {
    glutMainLoop();
}