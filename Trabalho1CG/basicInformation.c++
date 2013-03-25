#include <basicInformation.h>

GLfloat scale(GLint number) {
    static GLint normal = 250;
    return (GLfloat) number / normal;
}