//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <iostream>
#include <vector>

using namespace std;

class Universe {
public:
    Universe(int period , int N);
    vector<double> addVectors (vector<double> currArray, const vector<double>& hypeVec);
    void GenerateUniverse(int currIndex, vector<double> currArray, vector<vector<double> >& sol, const vector<vector<double> >& hyperSpace);

protected:
    int period;
    int N;
};

#endif // UNIVERSE_H
