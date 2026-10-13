//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//main file

#include "NBL_Reference.h"
#include "Hyperspace.h"
#include "Achilles_Ankle_Universe.h"
#include "SuperpositionGen.h"
#include "NBL_Bit_String.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    cout<<"Starting Program"<<endl;
    int const N = 32;// Parameter for bit resolution
    int const period = 2000;//Number of clock cycles (Length of RTW)
    double LowAmp = 0.5;//Magnitude of Low reference RTWs
    double HighAmp = 1.0;//Magnitude of High reference RTWs

    cout<<"Start Generating References"<<endl;
    NBL_Reference* MyRefrences = new NBL_Reference (period , LowAmp, HighAmp, N);
    cout<<"Finished Generating References"<<endl;

    double** TheHigh = new double *[N];
    double** TheLow = new double *[N];

    for (int k = 0 ; k < N ; k++)
    {
        TheHigh [k] = new double [period];
        TheLow [k] = new double [period];
    }

    for (int j = 0 ; j < N; j++)
    {
        for (int i = 0 ; i <period ; i++){
            TheHigh[j][i] = MyRefrences->GetHighReferences()[j][i];
            TheLow[j][i] = MyRefrences->GetLowReferences()[j][i];
        }

    }
    ofstream ProblemFile1;
    ProblemFile1.open ("Problem1_Hyperspace.txt");

    ProblemFile1<<"PROBLEM # 1 : ... "<<endl;
    double sstr[period];
    int bstr[N]={ 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 };// numerical example to generate hyperspace vector
    //NOTE: There is no exception handling for when number of bits in numerical example does not match the bit resolution parameter N
    NBL_Bit_String* newbitstring = new NBL_Bit_String(period , N, MyRefrences, bstr);

    for (int v=0 ; v < period ;  v++)
    {
        sstr[v]= newbitstring->Get_NBL_String()[v] ;
        ProblemFile1<<"search string"<<"  "<<v <<" : "<<  sstr[v]<<endl;
    }


    SuperpositionGen* Hat = new SuperpositionGen(TheLow, TheHigh, period, N);
    Hat->Generate_superposition();
    double* Hat1Sup = Hat->Get_superposition();//Achilles ankle method to generate Universe


    Achilles_Ankle_Universe* AAU = new Achilles_Ankle_Universe(TheLow, TheHigh , period, N);

    AAU->Generate_superposition();// Note that Generates the Logarithmically altered superposition


    ProblemFile1.close();
    return 0;
}


