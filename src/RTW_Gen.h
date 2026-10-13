//INBL Simulation
//Code for Paper “EXPLORATION OF THE NON-ZERO UNIVERSE IN INSTANTANEOUS NOISE-BASED LOGIC” (Manuscript ID: RSOS-242285)
//Nasir Kenarangui, Laszlo Kish, Arthur Powalka

//RTW Generator for each reference noise, one for H one for L

#ifndef RTW_GEN_H
#define RTW_GEN_H

using namespace std;

class RTW_Gen {
public:
    RTW_Gen (int period, double LowWave, double HighWave);

    double* GetRTW() const {return RTW;}

private:
    void GenerateRTW();

protected:
    int period;
    double LowWave;
    double HighWave;
    double* RTW;
};

#endif // RTW_GEN_H
