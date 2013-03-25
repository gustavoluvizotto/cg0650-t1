/* 
 * File:   CartesianCircle.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 3:00 PM
 */

#ifndef CARTESIANCIRCLE_H
#define	CARTESIANCIRCLE_H

#include <BasicCircle.h>

class CartesianCircle : public BasicCircle{
public:
    CartesianCircle(GLint radius);
    
    virtual ~CartesianCircle();
    
    Point2D algorithm();
    
private:

};

#endif	/* CARTESIANCIRCLE_H */

