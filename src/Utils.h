//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

namespace utils
{
    inline void printArray(const double *const myArray, int length)
    {
        for (int i = 0; i < length; ++i)
        {
            cout << myArray[i] << " ";
        }
        cout << endl;
    }

    inline void printArrays(const double *const *const myArrays, int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            printArray(myArrays[i], col);
        }
        cout << endl;
    }

    inline void printVector(const vector<double>& vec)
    {
        for (int i = 0; i< vec.size(); ++i)
        {
            cout<<vec[i] << " ";
        }
        cout << endl;

    }

    inline void printVectors(const vector<vector<double> >& vecs)
    {
        for (int i = 0; i < vecs.size(); ++i)
        {
            printVector(vecs[i]);
        }

    }

    inline vector<double> addArrays(vector<double> currArray, const vector<double>& hypeVec)
    {
        vector<double> sol;
        for (int i = 0; i < currArray.size(); ++i)
        {
            sol.push_back(currArray[i] + hypeVec[i]);
        }
        return sol;
    }

    inline double* multiplyArrays(double* first, double* second, int N)
    {
        double* value = new double[N];
        for (int i = 0; i < N; ++i)
        {
            value[i] = first[i] * second[i];
        }
        return value;
    }
};

#endif // UTILS_H
