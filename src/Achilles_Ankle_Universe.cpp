//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "Achilles_Ankle_Universe.h"
#include "Utils.h"
#include <limits>
#include <fstream>
#include <iostream>
#include <cmath>

Achilles_Ankle_Universe::Achilles_Ankle_Universe(double** LowR,  double** HighR, int peri, int num)
{
    LowRef = LowR;
    HighRef = HighR;
    period = peri;
    N = num;

}

void Achilles_Ankle_Universe::Generate_superposition()
{

    ofstream Unifile;
    Unifile.open ("Universe_Logarithmically_Manipulated.txt");
    double SumValue = 0;
    double* Ut = new double[period];
    double* sigOp = new double[period];
    double* Superposition =new double[period];

    for (int j = 0 ; j < period ; j++)
    {
        Ut[j] = 1.0;
        sigOp[j] =1.0;
    }

    //utils::printArray(Ut, period);
    //utils::printArray(sigOp, period);
    for (int j = 0 ; j < period ; j++)
    {
        for(int i = 0 ; i< N ; i++)
        {
            SumValue = LowRef[i][j] + HighRef[i][j];
            Ut[j] *= SumValue;

        }
        if (abs(Ut[j]) < std::numeric_limits<double>::epsilon())
        {
            Ut[j] = 0.0;
        }

        if (Ut[j] < 0)
            sigOp[j] = -1.0;
        else
            sigOp[j] = 1.0;
    }
    //  utils::printArrays(LowRef, N, period);
    //  utils::printArrays(HighRef, N, period);
    //  utils::printArray(Ut, period);
    //  utils::printArray(sigOp, period);

    for (int j=0;  j < period ; j++)
    {
        Superposition[j] = sigOp[j] * log10(pow(2 , N)* abs(Ut[j]));
        Unifile << Superposition[j] << endl;
        //cout << log10(abs(Ut[j])) << endl;
    }
//    utils::printArray(Superposition, period);
    Unifile.close();

}

void Achilles_Ankle_Universe::Modify_superposition(double* sst)
{

    ofstream MUfile;
    MUfile.open ("Modified Universe.txt");
    double SumValue = 0;
    double* Ut = new double[period];
    double* Um = new double[period];
    double* sigOp = new double[period];
    double* Superposition =new double[period];

    for (int k = 0 ; k < period ; k++)
    {
        Ut[k] = 1.0;
        Um[k] = 0;
        sigOp[k] =1.0;
    }

    for (int h = 0 ; h < period ; h++)
    {
        for(int i = 0 ; i< N ; i++)
        {
            SumValue = LowRef[i][h] + HighRef[i][h];
            Ut[h] *= SumValue;
        }
        Um[h]=Ut[h]-sst[h];
    }

    for (int j = 0 ; j < period ; j++)
    {
        if (abs(Um[j]) < std::numeric_limits<double>::epsilon())
        {
            Um[j] = 0.0;
        }

        if (Um[j] < 0)
            sigOp[j] = -1.0;
        else
            sigOp[j] = 1.0;
    }

    for (int l=0;  l < period ; l++)
    {
        Superposition[l] = sigOp[l] * log10(pow(2 , N)* abs(Um[l]));
        MUfile << Superposition[l] << endl;
    }
    MUfile.close();

}
