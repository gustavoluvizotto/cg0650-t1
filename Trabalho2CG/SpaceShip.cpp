/* 
 * File:   SpaceShip.cpp
 * Author: gilvolpe
 * 
 * Created on May 29, 2013, 2:25 PM
 */

#include "SpaceShip.h"

SpaceShip::SpaceShip(Point3D point, GLfloat angleUpdate) : Objects(point, angleUpdate) {

    Load3DS(&spaceShip, "spaceship.3ds");

    // The Function LoadBitmap() return the current texture ID
    spaceShip.id_texture = LoadBitmap("spaceshiptexture.bmp");

    if (spaceShip.id_texture == -1) {
        cout << "Image file: spaceshiptexture.bmp not found\n" << endl;
        //MessageBox(NULL,"Image file: spaceshiptexture.bmp not found", "Zetadeck",MB_OK | MB_ICONERROR);
        exit(1);
    }

    moveForward = FORWARD_SPACE_SHIP;
    moveBackward = BACKWARD_SPACE_SHIP;

    Point3D direction(0.0f, 0.0f, 1.0f);
    this->direction = direction;

    Point3D versor(0.0f, 1.0f, 0.0f);
    this->versorAzimutal = versor;

    Point3D elevation(1.0f, 0.0f, 0.0f);
    this->versorElevation = elevation;

    error = 0.0001;
    this->angleZ = this->angleY = this->angleX = 0;
}

SpaceShip::~SpaceShip() {
}

void SpaceShip::specificDraw() {

    translateShip();

    rotateShip();

    glRotatef(180, 0, 0, 1);
    glRotatef(90, 1, 0, 0);

    glBindTexture(GL_TEXTURE_2D, this->spaceShip.id_texture); // We set the active texture

    glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
    for (int l_index = 0; l_index < spaceShip.polygons_qty; l_index++) {

        //----------------- FIRST VERTEX -----------------
        // Texture coordinates of the first vertex
        glTexCoord2f(spaceShip.mapcoord[ spaceShip.polygon[l_index].a ].u,
                spaceShip.mapcoord[ spaceShip.polygon[l_index].a ].v);
        // Coordinates of the first vertex
        glVertex3f(spaceShip.vertex[ spaceShip.polygon[l_index].a ].x,
                spaceShip.vertex[ spaceShip.polygon[l_index].a ].y,
                spaceShip.vertex[ spaceShip.polygon[l_index].a ].z); //Vertex definition

        //----------------- SECOND VERTEX -----------------
        // Texture coordinates of the second vertex
        glTexCoord2f(spaceShip.mapcoord[ spaceShip.polygon[l_index].b ].u,
                spaceShip.mapcoord[ spaceShip.polygon[l_index].b ].v);
        // Coordinates of the second vertex
        glVertex3f(spaceShip.vertex[ spaceShip.polygon[l_index].b ].x,
                spaceShip.vertex[ spaceShip.polygon[l_index].b ].y,
                spaceShip.vertex[ spaceShip.polygon[l_index].b ].z);

        //----------------- THIRD VERTEX -----------------
        // Texture coordinates of the third vertex
        glTexCoord2f(spaceShip.mapcoord[ spaceShip.polygon[l_index].c ].u,
                spaceShip.mapcoord[ spaceShip.polygon[l_index].c ].v);
        // Coordinates of the Third vertex
        glVertex3f(spaceShip.vertex[ spaceShip.polygon[l_index].c ].x,
                spaceShip.vertex[ spaceShip.polygon[l_index].c ].y,
                spaceShip.vertex[ spaceShip.polygon[l_index].c ].z);
    }

//    cout << angleX << " " << angleY << endl;
    
    glEnd();
}

void SpaceShip::translateShip() {
    Point3D point = getPoint();
    glTranslatef(point._x, point._y, point._z);
}

void SpaceShip::rotateShip() {

    //rodar em torno do vetor direcao
    glRotatef(angleY, versorAzimutal._x, versorAzimutal._y, versorAzimutal._z);
    glRotatef(angleX, versorElevation._x, versorElevation._y, versorElevation._z);
}

void SpaceShip::updatePosition(bool forward) {
    
    updateDirection();
    
    Point3D point = getPoint();

    //atualzicao X
    if (-error < direction._x && direction._x > error) {
        point._x += (forward ? -moveForward : moveBackward);
    } else {
        if (-error > direction._x && direction._x < error)
            point._x += (forward ? moveForward : -moveBackward);
    }

    //atualzicao Y
    if (-error < direction._y && direction._y > error) {
        point._y += (forward ? -moveForward : moveBackward);
    } else {
        if (-error > direction._y && direction._y < error)
            point._y += (forward ? moveForward : -moveBackward);
    }

    //atualizacao eixoZ
    if (-error < direction._z && direction._z > error) {
        point._z += (forward ? -moveForward : moveBackward);
    } else {
        if (-error > direction._z && direction._z < error)
            point._z += (forward ? moveForward : -moveBackward);
    }

    setPoint(point);
}

void SpaceShip::updateRotationAroundDirector(bool forward) {

    GLfloat update = getUpdateAngle();

    this->angleY += (forward) ? update : -update;

    if (this->angleY >= 360)
        this->angleY = 0;

    if (this->angleY <= -360)
        this->angleY = 0;
}

void SpaceShip::updateRotationAroundVersor(bool forward) {

    GLfloat update = getUpdateAngle();

    angleX += (forward) ? update : -update;

    if (angleX >= 360)
        angleX = 0;

    if (angleX <= -360)
        angleX = 0;
}

void SpaceShip::updateDirection() {

    GLfloat x = direction._x;
    GLfloat y = direction._y;
    GLfloat z = direction._z;

    GLfloat alphaY = angleY * M_PI / 180.0f;
    GLfloat alphaX = angleX * M_PI / 180.0f;

//    cout << "Angles" << endl;
//    cout << alphaX << " " << alphaY << endl;

    x = sin(alphaY) * cos(alphaX);
    y = -sin(alphaX);
    z = cos(alphaX) * cos(alphaY);

//    cout << "Position" << endl;
//    cout << x << " " << y << " " << z << endl;

    direction._x = x;
    direction._y = y;
    direction._z = z;
}

void SpaceShip::updateVersor() {

    GLfloat y = direction._y;
    GLfloat x = direction._x;
    GLfloat z = direction._z;

    GLfloat alphaY = angleY * M_PI / 180.0f;
    GLfloat alphaX = angleX * M_PI / 180.0f;

//    cout << "Angles" << endl;
//    cout << alphaY << " " << endl;

    x = sin(alphaY);
    z = cos(alphaY);

//    cout << "Position" << endl;
//    cout << x << " " << " " << z << endl;

    direction._x = x;
    direction._z = z;
}

void SpaceShip::controlOfSpaceRotation(int key, int x, int y) {
    bool evaluate = true;
    switch (key) {
        case GLUT_KEY_UP:
            this->updateRotationAroundVersor(evaluate);
            break;
        case GLUT_KEY_DOWN:
            this->updateRotationAroundVersor(!evaluate);
            break;
        case GLUT_KEY_LEFT:
            this->updateRotationAroundDirector(evaluate);
            break;
        case GLUT_KEY_RIGHT:
            this->updateRotationAroundDirector(!evaluate);
            break;
    }
}

void SpaceShip::controlOfSpaceTranslation(unsigned char key, int x, int y) {
    bool evaluate = true;
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'w':
        case 'W':
            this->updatePosition(evaluate);
            break;
        case 's':
        case 'S':
            this->updatePosition(!evaluate);
            break;
    }
}
