/* 
 * File:   Statistic.h
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 *
 * Created on April 1, 2013, 1:14 PM
 */

#ifndef STATISTIC_H
#define	STATISTIC_H

#include "basicInformation.h"

#include <unistd.h>
#include <sys/times.h>
#include <ctime>
#include <vector>

#include "plplot/plplot.h"


#define NUMBERS_OF_POINTS 250

class Statistic {
public:

    Statistic(char *type);
    Statistic(const Statistic& orig);
    virtual ~Statistic();

    void showStatistic();
    void startCounter();
    void stopCounter();
    void setRadius(int radius);
    clock_t elapsedTime();

private:
    struct tms oldTimer, newTimer;
    vector<long double> data2Analisys[NUMBERS_OF_POINTS];

    int vectorPosition;
    long double variance[NUMBERS_OF_POINTS];
    long double standardDeviantion[NUMBERS_OF_POINTS];
    long double average[NUMBERS_OF_POINTS];

    char type[10];
    
    clock_t timeSub();
    void setData();          // insere elapsedTime em vectorPosition de data2Analisys[]
    void mean();
    void stdDeviationAndVar();
};

#endif	/* STATISTIC_H */

