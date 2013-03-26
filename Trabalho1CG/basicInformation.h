/* 
 * File:   basicInformation.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 2:36 PM
 */

#ifndef BASICINFORMATION_H
#define	BASICINFORMATION_H

#include <GL/glut.h>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

#define _3D_
#ifndef _3D_
#define _2D_
#endif

using namespace std;

#define SIDE_SIZE       500
#define SCALE           250


GLfloat scale(GLint number);
GLint unscale(GLfloat number);

struct Point2D {
    GLfloat _x, _y;

    Point2D(GLint x = 0, GLint y = 0) {
        _x = scale(x);
        _y = scale(y);
    }
};

struct Point3D {
    GLfloat _x, _y, _z;

    /*
     * 0 - X rot y plane
     * 1 - y rot z plane
     * 2 - x rot z plane
     */

    GLint _plane;

    Point3D(GLint x = 0, GLint y = 0, GLint z = 0, GLint plane = 0) {
        _x = scale(x);
        _y = scale(y);
        _z = scale(z);
        if (plane > 2)
            _plane = 2;
        else
            _plane = plane;
    }
};

typedef struct Point2D Point2D;

struct SizeRadiusDraw {
    GLint sizeCartesian[250], sizePolar[250], sizeMidPoint[250];

    SizeRadiusDraw() {
        GLint random;
        for (GLint i = 0; i < 250; i++) {
            this->sizeCartesian[i] = i + 1;
            this->sizePolar[i] = i + 1;
            this->sizeMidPoint[i] = i + 1;
        }
    }
};

typedef struct SizeRadiusDraw SizeRadiusDraw;


#endif	/* BASICINFORMATION_H */

