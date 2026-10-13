//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//Achilles Ankle algorithm to generate the Universe
//This class contains distribution analysis of spikes

#ifndef SUPERPOSITIONGEN_H
#define SUPERPOSITIONGEN_H
#include <iostream>
#include <vector>

using namespace std;

class SuperpositionGen {
public:
    SuperpositionGen(double** LowRef,  double** HighRef, int period, int N);

    void Generate_superposition();
    double* Get_superposition() const {return Superposition;}

protected:

    double** LowRef;
    double** HighRef;
    int period;
    int N;
    double* Superposition;
    double* Magnitude;
};

#endif // SUPERPOSITIONGEN_H
