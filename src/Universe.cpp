//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "Universe.h"
#include <vector>

using namespace std;

Universe::Universe(int peri , int num)
{
    period = peri;
    N = num;
}

void Universe::GenerateUniverse(int currIndex, vector<double> currArray, vector<vector<double> >& sol, const vector<vector<double> >& hyperSpace)
{
    //printVectors(hyperSpace);
    if (currIndex == hyperSpace.size() - 1)
    {
        sol.push_back(currArray);
        return;
    }

    // Don't add anything but increment the counter
    this->GenerateUniverse(currIndex + 1, currArray, sol, hyperSpace);

    vector<double> secondArray = addVectors(currArray, hyperSpace[currIndex + 1]);
    this->GenerateUniverse(currIndex + 1, secondArray, sol, hyperSpace);
}

vector<double> Universe::addVectors (vector<double> currArray, const vector<double>& hypeVec)
{
    vector<double> sol;
    for (int i = 0; i < currArray.size(); ++i)
    {
        sol.push_back(currArray[i] + hypeVec[i]);
    }
    return sol;
}
