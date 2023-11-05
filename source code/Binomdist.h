#ifndef BINOMDIST
#define BINOMDIST
#include <iostream>
#include <cmath>
#include <vector>

class Binomial_Distribution {
public:
    int n;
    int x;
    int pNumerator;
    int pDenominator;
    double probability;
    double q;

    Binomial_Distribution();
    double binomdist();
};

#endif
