/* 
 * File:   Render.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

/*
 *      R G B Valor Binario     Cor
 *      0 0 0 0                 preto
 *      0 0 1 1                 azul
 *      0 1 0 2                 verde
 *      0 1 1 3                 turquesa
 *      1 0 0 4                 vermelho
 *      1 0 1 5                 magenta
 *      1 1 0 6                 amarelo
 *      1 1 1 7                 branco
 */

#include "Render.h"
#include <basicInformation.h>

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

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // desabilita profundidade (coordenada z)
    glDisable(GL_DEPTH_TEST);
    
    // cor de fundo da janela: 1,1,1,1 = branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //comando nao está funcionando ???
    
    glutInitWindowSize(sizeX, sizeY); // definindo o tamanho da tela
    glutCreateWindow("Primeiro Trabalho de Computacao Grafica");

    glutDisplayFunc(drawScene); // metodo que faz os desenhos
    glutKeyboardFunc(handleKeyPress);
}

/*
 * Metodo para desenhar na tela
 */
void Render::drawScene() {

    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    grid();

    glutSwapBuffers();
}

/*
 * funcao que desenha uma malha na tela
 */
void Render::grid() {

    glColor3f(1, 0, 0);
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

GLfloat Render::scale(GLint number) {
    static GLint normal = 250;
    return (GLfloat) number / normal;
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