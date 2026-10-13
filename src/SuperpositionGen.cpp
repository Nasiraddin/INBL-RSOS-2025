//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "SuperpositionGen.h"
#include "Utils.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <map>

SuperpositionGen::SuperpositionGen(double** LowR,  double** HighR, int peri, int num)
{
    LowRef = LowR;
    HighRef = HighR;
    period = peri;
    N = num;
}

void SuperpositionGen::Generate_superposition()
{

    ofstream SuperFile;
    SuperFile.open ("Universe_unmanipulated.txt");
    double SumValue = 0;
    Superposition =new double[period];
    Magnitude =new double[period];


    for (int j = 0 ; j < period ; j++)
    {
        Superposition[j] = 1.0;
        Magnitude[j] = 1.0;
    }
    for (int j = 0 ; j < period ; j++)
    {
        for(int i = 0 ; i< N ; i++)
        {
            SumValue = LowRef[i][j] + HighRef[i][j];
            Superposition[j] *= SumValue;
        }
        Magnitude[j] = std::abs(Superposition[j]);
    }

    std::map<double, int> peakFrequencyMap;
    for (int j=0;  j < period ; j++)
    {

        SuperFile << Superposition[j] << endl;
        if (peakFrequencyMap.find(Superposition[j]) != peakFrequencyMap.end())
        {
            ++peakFrequencyMap[Superposition[j]];
        }
        else
        {
            peakFrequencyMap[Superposition[j]] = 1;
        }

    }

    std::map<double, int> peakMagnitudeMap;
    for (int j=0;  j < period ; j++)
    {
        if (peakMagnitudeMap.find(Magnitude[j]) != peakMagnitudeMap.end())
        {
            ++peakMagnitudeMap[Magnitude[j]];
        }
        else
        {
            peakMagnitudeMap[Magnitude[j]] = 1;
        }
    }
    // loop through map and write to file
    ofstream peakDistribFile;
    ofstream magDistribFile;
    peakDistribFile.open ("Distribution_of_Spikes.txt");
    magDistribFile.open ("Distribution_of_Magnitudes.txt");
    for (auto i = peakFrequencyMap.begin(); i != peakFrequencyMap.end(); ++i)
    {
        peakDistribFile << i->first << " " << i->second << endl;
    }
    for (auto i = peakMagnitudeMap.begin(); i != peakMagnitudeMap.end(); ++i)
    {
        magDistribFile << i->first << " " << i->second << endl;
    }
    magDistribFile.close();
    peakDistribFile.close();
    SuperFile.close();
}
