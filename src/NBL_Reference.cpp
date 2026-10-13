//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "NBL_Reference.h"
#include "NoiseBitGen.h"
#include <fstream>
#include <iostream>

//NBL_Reference Arguments are passed to NoiseBitGen and then on to RTW_Gen
//mini/maxi are the +/- amplitude for the low RTW and high RTW respectively
//peri is the number of clock cycles in the RTW, num is the number of bits
NBL_Reference::NBL_Reference(int peri , double mini, double maxi, int num){
    N = num;
    LowAmp = mini;
    HighAmp = maxi;
    period = peri;
    this->GenerateAll();
}

// Allocating array of rows (number of bits) and columns (length of RTW)
// The two dimensional arrays containing all the reference noise bits
// one 2d array for high noise bits and one 2d array for low noise bits
void NBL_Reference::GenerateAll(){

    ofstream referfile;
    referfile.open ("Reference.txt");

    highReferences = new double*[N];
    lowReferences = new double*[N];

    for (int k = 0 ; k < N ; k++)
    {
        highReferences [k] = new double [period];
        lowReferences [k] = new double [period];

    }
    double* d;
    double* c;

    for (int i = 0 ; i < N ; i++)
    {
        NoiseBitGen* Generator = new NoiseBitGen( period, LowAmp, HighAmp );
        d = Generator->GetHigh();
        c = Generator->GetLow();
        referfile<< endl << i <<" Noise bit: "<< endl;
        //the 2-d array has already been allocated, copying the array elements
        for (int j = 0 ; j < period ; j++)
        {
            highReferences [i][j] = d[j];
            lowReferences [i][j] = c[j];

        referfile<< highReferences[i][j] <<" & "<<lowReferences[i][j]<<"    ";
        }
      referfile << endl;
    }
    referfile.close();
}
