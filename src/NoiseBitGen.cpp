//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "NoiseBitGen.h"
#include "RTW_Gen.h"

// Arguments will be passed to the RTW_Gen
// May have been better named, but mini is the -/+ Amplitude for the low noise bit
// maxi is the -/+ Amplitude for the high noise bit
// GenarateHigh and GenerateLow methods implementing appropriate H/L amplitudes
// Will store in separate fields respectively High RTW/Low RTW representing (single) noise bit
NoiseBitGen::NoiseBitGen(int peri, double mini, double maxi){
    period = peri;
    LowAmp = mini;
    HighAmp =  maxi;
    this->GenerateHigh();
    this->GenerateLow();
}

void NoiseBitGen::GenerateHigh(){

    double HighWave = HighAmp;
    double LowWave = - HighAmp;


    RTW_Gen* HighGener = new RTW_Gen(period, LowWave, HighWave);

    High = new double[period];

    double* p = new double[period];
    p = HighGener->GetRTW();
    // Points only to first element,
    // So must populate High field

    for (int i = 0 ; i< period; i++)
    {
        High[i]= p[i];
    }

}

void NoiseBitGen::GenerateLow(){

    double HighWave = LowAmp;
    double LowWave = - LowAmp;

    RTW_Gen* LowGener = new RTW_Gen( period, LowWave, HighWave);

    Low = new double[period];

    double* p = new double[period];
    p = LowGener->GetRTW();

    for (int i = 0 ; i< period; i++)
    {
        Low[i]= p[i];
    }
// Just as High Array, stored in NoiseBitGen fields
}
