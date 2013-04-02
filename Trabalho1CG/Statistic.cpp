/* 
 * File:   Statistic.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * 
 * Created on April 1, 2013, 1:14 PM
 */

#include "Statistic.h"

Statistic::Statistic(char *type) {
    for (int i = 0; i < NUMBERS_OF_POINTS; i++)
        variance[i] = standardDeviantion[i] = average[i] = 0;
    strcpy(this->type, type);
}

Statistic::Statistic(const Statistic& orig) {
}

Statistic::~Statistic() {
}

void Statistic::startCounter() {
    times(&oldTimer);
    return;
}

void Statistic::stopCounter() {
    times(&newTimer);
    setData();
    return;
}

clock_t Statistic::timeSub() {
    clock_t sub;
    sub = (newTimer.tms_stime + newTimer.tms_utime) - (oldTimer.tms_stime - oldTimer.tms_utime);
//    cout << sub << endl;
    return sub;
}

clock_t Statistic::elapsedTime() {
    return timeSub();
}

void Statistic::setData() {
//    cout << vectorPosition-1 << endl;
    data2Analisys[vectorPosition-1].push_back(elapsedTime());
    return;
}

void Statistic::mean() {
    int i;

    vector<clock_t>::iterator it;
    for (i = 0; i < 250; i++) {
        for (it = data2Analisys[i].begin(); it != data2Analisys[i].end(); it++)
            average[i] += *it;
        average[i] = (double) average[i] / data2Analisys[i].size();
    }
    return;
}

void Statistic::stdDeviationAndVar() {
    int i;

    vector<clock_t>::iterator it;
    for (i = 0; i < 250; i++) {
        for (it = data2Analisys[i].begin(); it != data2Analisys[i].end(); it++)
            standardDeviantion[i] = pow(*it - average[i], 2);
        standardDeviantion[i] = (double) standardDeviantion[i] / data2Analisys[i].size();
        variance[i] = standardDeviantion[i];
        standardDeviantion[i] = sqrt(standardDeviantion[i]);
    }
    return;
}

void Statistic::showStatistic() {
    for (int i = 0; i < NUMBERS_OF_POINTS; i++)
        cout << i + 1 << " average: " << average[i] << " stddev: " << standardDeviantion[i] << " var: " << variance[i] << endl;
}

void Statistic::setRadius(int radius) {
    vectorPosition = radius;
    return;
}