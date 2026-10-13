//INBL Simulation 
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

#include "NBL_Bit_String.h"
#include "NBL_Reference.h"
#include <vector>
#include <iostream>

NBL_Bit_String::NBL_Bit_String(int peri, int num, NBL_Reference* NBRef  , int* bstring)
{
    Highbits = new double *[num];
    Lowbits = new double *[num];

    for (int k = 0 ; k < num ; k++)
    {
        Highbits [k] = new double [peri];
        Lowbits [k] = new double [peri];
    }

    for (int j = 0 ; j < num; j++)
    {
        for (int i = 0 ; i <peri ; i++){
            Highbits[j][i] = NBRef->GetHighReferences()[j][i];
            Lowbits[j][i] = NBRef->GetLowReferences()[j][i];
        }
    }
    period = peri;
    N = num;
    binary_string = bstring;
    this ->generateNBLString();
}

void NBL_Bit_String::generateNBLString()
{

    NBL_string_vector = new double[period];

    for (int j = 0 ; j < period ; j++)
    {
        NBL_string_vector[j] = 1.0;
    }
    for (int j = 0 ; j < period ; j++)
    {
        for(int i = 0 ; i< N ; i++)
        {
            if (binary_string[i] == 0)
            {
                NBL_string_vector[j] *= Lowbits[i][j];
            }
            else if (binary_string[i]== 1)
            {
                NBL_string_vector[j] *= Highbits[i][j];
            }
            else
            {
                std::cout<< "error not 0 or 1"<<std::endl;
            }
        }
    }
}
