//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//Reference noises are generated based on RTW and symmetric/asymmetric scheme set in INBL_Engine.cpp

#ifndef NOISE_BIT_GEN_H
#define NOISE_BIT_GEN_H
#include <iostream>
#include <vector>

using namespace std;

class NoiseBitGen {
public:
    NoiseBitGen(int period, double LowAmp, double HighAmp);
    double* GetHigh() const {return High;}
    double* GetLow() const {return Low;}

private:
    void GenerateHigh();
    void GenerateLow();

protected:
    int period;
    double LowAmp;
    double HighAmp;
    double* High;
    double* Low;
};

#endif // NOISE_BIT_GEN_H
