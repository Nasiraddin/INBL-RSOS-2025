//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "RTW_Gen.h"
#include <cmath>
#include <random>
//#include <stdlib.h>

// Generates RTW, where WLow is the minima and WHigh is the maxima of the RTW
// peri is the number of clock cycles
RTW_Gen::RTW_Gen(int peri, double WLow, double WHigh){
    period = peri;
    LowWave = WLow;
    HighWave =  WHigh;
    this->GenerateRTW();
}

void RTW_Gen::GenerateRTW(){
    //Allocate array for single RTW stored in RTW_Gen fields
    RTW = new double[period];
    int t = 0;

    for (int i = 0; i < period ; i++)
    {
        //static std::default_random_engine eng{100};
        static std::mt19937_64 eng{100};
        static std::uniform_int_distribution<int> dist{0, 1};
        int t = dist(eng);
        if (t == 0)
        {
            RTW[i] = LowWave;//Minima of RTW -1
        }
        else
        {
            RTW[i] = HighWave;//Maxima of RTW 1
        }
    }
}
