//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "Hyperspace.h"
#include "Utils.h"
#include <vector>
#include <iostream>

// Hyperspace utilizes the Reference noise bits,
// Thus the Arguments are passed ass follows
// mini/maxi represent the Amplitudes for Low RTW/High RTW respectively
Hyperspace::Hyperspace(int peri , double mini, double maxi, int num )
{
    N = num;
    LowAmp = mini;
    HighAmp = maxi;
    period = peri;
}

void Hyperspace::generateHyperspace(int currIndex, double* currArray, vector<vector<double> >& sol, double** Low , double** High)
{
    if (currIndex == N - 1)
    {
        vector<double> w(currArray, currArray + period);
        sol.push_back(w);
        return;
    }

    // TODO don't forget to handle memory clean up
    double* firstArray = this->multiplyArrays(currArray, Low[currIndex + 1]);
    this->generateHyperspace(currIndex + 1, firstArray, sol, Low , High);

    double* secondArray = multiplyArrays(currArray, High[currIndex + 1]);
    this->generateHyperspace(currIndex + 1, secondArray, sol, Low , High);
}

double* Hyperspace::multiplyArrays(const double *const first, const double *const second)
{
//    cout << "MULT" << endl;
//    utils::printArray(first, period);
//    utils::printArray(second, period);
    double* value = new double[period];
    for (int i = 0; i < period; ++i)
    {
        value[i] = first[i] * second[i];
    }

  //  utils::printArray(value, period);
 //   cout << "COMPLETE" <<endl;
    return value;
}
