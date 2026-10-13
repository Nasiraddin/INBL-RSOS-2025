//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//This Class creates Logarithmically modified universe for better visualization

#ifndef ACHILLES_ANKLE_UNIVERSE_H
#define ACHILLES_ANKLE_UNIVERSE_H
#include <iostream>
#include <vector>

using namespace std;

class Achilles_Ankle_Universe {
public:
    Achilles_Ankle_Universe(double** LowRef,  double** HighRef, int period, int N);

    void Generate_superposition();
    //Modify_superposition generates the superposition where,
    //reference bit values associated with the search string are set to zero.
    void Modify_superposition(double* sst);
    double* Get_superposition() const {return Superposition;}

protected:

    double** LowRef;
    double** HighRef;
    int period;
    int N;
    double* Superposition;
};

#endif // ACHILLES_ANKLE_UNIVERSE_H
