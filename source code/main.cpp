#include <iostream>
#include "groupedData.h"

int main(){
    grouped_data data_kelompok;
    data_kelompok.get_Grouped_Data();
    data_kelompok.get_frequency_cummulative();
    data_kelompok.get_classInterval();
    system("cls");
    data_kelompok.show_Grouped_Data();

    /*double mode = data_kelompok.findMode();
    std::cout << "\nModus Data Kelompok: "  << mode << std::endl;

    double mean = data_kelompok.findMean();
    std::cout << "Mean Data Kelompok: "  << mean;

    double median = data_kelompok.findMedian();
    std::cout << "\nMedian Data Kelompok: "  << median << std::endl;

    double* kuartils = data_kelompok.findKuartil();
    for(int i=0; i<3; i++){
    std::cout << "Kuartil " << i+1 << ": " << kuartils[i] << std::endl;
    }
    delete[] kuartils;

    double desil = data_kelompok.findDesil(2);
    std::cout << "Desil Ke-2: " << desil << std::endl;

    double persentil = data_kelompok.findPersentil(96);
    std::cout << "Persentil Ke-96: " << persentil << std::endl;

    double interQuartileRange = data_kelompok.findInterQuartileRange();
    std::cout << "Nilai Jangkauan antarkuartil: " << interQuartileRange << std::endl;

    double meanDeviation = data_kelompok.findMeanDeviation();
    std::cout << "Nilai Simpangan rata-rata: " << meanDeviation << std::endl;

    double variance = data_kelompok.findVariance();
    std::cout << "Nilai Ragam(Variansi): " << variance << std::endl;

    double standardDeviation = data_kelompok.findStandardDeviation();
    std::cout << "Nilai Standar Deviasi: " << standardDeviation << std::endl;*/

    return 0;
}