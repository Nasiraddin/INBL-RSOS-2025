//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//This function provides for assignment of reference noises to binary string

#ifndef NBL_BIT_STRING_H
#define NBL_BIT_STRING_H
#include <vector>
#include "NBL_Reference.h"

using namespace std;

class NBL_Bit_String {
public:
    NBL_Bit_String(int period, int N, NBL_Reference* Refs  , int* binary_string );

    double* Get_NBL_String() const {return NBL_string_vector;}
    void generateNBLString();

protected:
    int period;
    int N;
    double** Lowbits;
    double** Highbits;
    int* binary_string;
    double* NBL_string_vector;
};

#endif // NBL_BIT_STRING_H
