//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//Class for generation of Hyperspace vectors from bit string products of the noise bits

#ifndef HYPERSPACE_H
#define HYPERSPACE_H
#include <iostream>
#include <vector>

using namespace std;

class Hyperspace {
public:
    Hyperspace(int period , double LowAmp , double HighAmp , int N );
    double* multiplyArrays(const double *const first, const double *const second);
    void generateHyperspace(int currIndex, double* currArray, vector<vector<double> >& sol, double** Low , double** High);
    void printArray(const double *const myArray, int length);

protected:
    int period;
    double LowAmp;
    double HighAmp;
    int N;
};

#endif // HYPERSPACE_H
