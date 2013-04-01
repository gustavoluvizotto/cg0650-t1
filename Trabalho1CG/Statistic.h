/* 
 * File:   Statistic.h
 * Author: gilvolpe
 *
 * Created on April 1, 2013, 1:14 PM
 */

#ifndef STATISTIC_H
#define	STATISTIC_H

#include <basicInformation.h>

#include <unistd.h>
#include <sys/time.h>
#include <ctime>
#include <vector>

#define NUMBERS_OF_POINTS 250

class Statistic {
public:
    
    Statistic();
    Statistic(const Statistic& orig);
    virtual ~Statistic();

    void showStatistic();

private:
    struct tms oldTimer, newTimer;
    vector<double> data2Analisys[NUMBERS_OF_POINTS];

    int vectorPosition;
    double variance[NUMBERS_OF_POINTS];
    double standardDeviantion[NUMBERS_OF_POINTS];
    double average[NUMBERS_OF_POINTS];

    void startCounter();
    void stopCounter();
};

#endif	/* STATISTIC_H */

