//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//This class generates the INBL reference noises

#ifndef NBL_REFERENCE_H
#define NBL_REFERENCE_H
#include <iostream>
#include <vector>

using namespace std;

class NBL_Reference {
public:
    NBL_Reference(int period , double LowAmp , double HighAmp , int N);

    double** GetHighReferences() const {return highReferences;}
    double** GetLowReferences() const {return lowReferences;}

private:
    void GenerateAll();

protected:
    int period;
    double LowAmp;
    double HighAmp;
    int N;
    double** highReferences;
    double** lowReferences;

};

#endif // NBL_REFERENCE_H
