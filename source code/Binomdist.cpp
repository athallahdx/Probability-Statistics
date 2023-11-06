#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include "Binomdist.h"

Binomial_Distribution::Binomial_Distribution() {
    system("cls");
    std::cout << "BINOMIAL DISTRIBUTION CALCULATOR\n";
    std::cout << "===================================\n";
    std::cout << "\nMasukkan Nilai n (Banyaknya Percobaan): ";
    std::cin >> n;
    std::cout << "Masukkan Nilai x (Jumlah keberhasilan yang diinginkan): ";
    std::cin >> x;
    std::cout << "Masukkan Peluang (Pembilang): ";
    std::cin >> pNumerator;
    std::cout << "Masukkan Peluang (Penyebut): ";
    std::cin >> pDenominator;
    probability = static_cast<double>(pNumerator) / static_cast<double>(pDenominator);
    q = 1.0 - probability;
}

double Binomial_Distribution::binomdist() {
    int dNumerator;
    int dDenominator;
    int fpb;

    double prob = static_cast<double>(pNumerator) / static_cast<double>(pDenominator);
    double probmin = 1.0 - prob;
    double combination = std::tgamma(n + 1) / (std::tgamma(x + 1) * std::tgamma(n - x + 1));
    double distribution = combination * std::pow(prob, x) * std::pow(probmin, (n - x));
    dNumerator=combination * std::pow(pNumerator, x) * std::pow((pDenominator-pNumerator), (n-x));
    dDenominator=std::pow(pDenominator,x) * std:: pow(pDenominator, (n-x));
    fpb=std::gcd(dNumerator, dDenominator);
    dNumerator=dNumerator/fpb;
    dDenominator=dDenominator/fpb;

    std::cout << "\nProbabilitas dalam bentuk pecahan: " << dNumerator << "/" << dDenominator << std::endl;


    return distribution;
}