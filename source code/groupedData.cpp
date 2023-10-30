#include <iostream>
#include <vector>
#include <cmath> 
#include "groupedData.h"


void grouped_data::get_Grouped_Data(){
    int row;
    int lowerBound;
    int upperBound;
    int freq;

    std::cout << "Berapa banyak baris data : ";
    std::cin >> row;
    for(int i=0; i<row; i++){
        std::cout << "Masukkan data baris ke-" << i+1 << ": ";
        std::cin >> lowerBound >> upperBound;
        std::cout << "Masukkan frekuensi: ";
        std::cin >> freq;
        data.push_back(std::make_pair(lowerBound, upperBound));
        frequency.push_back(freq);
    }
}



void grouped_data::show_Grouped_Data(){
        std::cout << "\nDATA KELOMPOK YANG TELAH DI-INPUT: \n";
        std::cout << " _____________________________\n";
        std::cout << "|    Data     |    Frekuensi  |\n";
        std::cout << " _____________________________\n";

        for(int i=0; i<data.size(); i++){
            std::cout << "|   " <<  data[i].first << "-" << data[i].second <<"     |        " << frequency[i] << "      |"  << std::endl; 
        }
        std::cout << " _____________________________\n";
}

double grouped_data::findMode(){
    int maxFrequency=frequency[0];
    int indexMax=0;
    int d1,d2;
    for(int i=1; i<frequency.size(); i++){
        if(frequency[i]>maxFrequency){
            maxFrequency=frequency[i];
            indexMax=i;
        }
    }

      if (indexMax == 0) {
        d1 = maxFrequency; 
        d2 = abs(maxFrequency - frequency[indexMax + 1]);
    } else if (indexMax == frequency.size() - 1) {
        d1 = abs(maxFrequency - frequency[indexMax - 1]);
        d2 = maxFrequency;
    } else {
        d1 = abs(maxFrequency - frequency[indexMax - 1]);
        d2 = abs(maxFrequency - frequency[indexMax + 1]);
    }

    double lowerBound=data[indexMax].first-0.5;
    int p=(data[indexMax].second-data[indexMax].first) + 1;

    double mode= lowerBound + (((double)d1/(d1+d2)) * p);
    return mode;
}

double grouped_data::findMean(){
    double sumFx=0.0;
    int sumF=0;

    for(int i=0; i<data.size(); i++){
        double midPoint=(data[i].first + data[i].second)/2.0;
        sumFx += midPoint * frequency[i];
        sumF += frequency[i];
    }

    if(sumF == 0){
        return 0.0;
    }

    return sumFx/sumF;
}

double grouped_data::findMedian(){
    std::vector<int> frequencyCummulative;
    int temp=0;

    for(int i=0; i<frequency.size(); i++){
        temp+=frequency[i];
        frequencyCummulative.push_back(temp); 
    }

    int totalFrequency=frequencyCummulative.back();
    double locateMedian=totalFrequency/2.0;

    int row; 
    for(row=0; row<frequencyCummulative.size(); row++){
       if(frequencyCummulative[row]>=locateMedian){
            break;
       }
    }

    double lowerBound=data[row].first-0.5;
    int previousCummulativeFrequency=(row==0) ? 0 : frequencyCummulative[row-1];
    double p=(data[row].second-data[row].first) +1;
    
    double median= lowerBound + ((  locateMedian-previousCummulativeFrequency) / frequency[row])*p;
    return median;
}

double* grouped_data::findKuartil() {
    std::vector<int> frequencyCummulative;
    int temp = 0;

    for(int i = 0; i < frequency.size(); i++){
        temp += frequency[i];
        frequencyCummulative.push_back(temp); 
    }

    int totalFrequency = frequencyCummulative.back();
    double locateKuartil1 = 0.25 * totalFrequency;
    double locateKuartil2 = 0.5 * totalFrequency;
    double locateKuartil3 = 0.75 * totalFrequency;

    int lowerBound1Index = -1, lowerBound2Index = -1, lowerBound3Index = -1;

    for(int i = 0; i < frequencyCummulative.size(); i++){
        if(lowerBound1Index == -1 && frequencyCummulative[i] >= locateKuartil1){
            lowerBound1Index = i;
        }
        if(lowerBound2Index == -1 && frequencyCummulative[i] >= locateKuartil2){
            lowerBound2Index = i;
        }
        if(lowerBound3Index == -1 && frequencyCummulative[i] >= locateKuartil3){
            lowerBound3Index = i;
        }
        if(lowerBound1Index != -1 && lowerBound2Index != -1 && lowerBound3Index != -1) {
            break; 
        }
    }

    double lowerBound1 = data[lowerBound1Index].first - 0.5;
    double lowerBound2 = data[lowerBound2Index].first - 0.5;
    double lowerBound3 = data[lowerBound3Index].first - 0.5;

    double* kuartilResults = new double[3];

    int p=(data[0].second-data[0].first)+1;
    kuartilResults[0] = lowerBound1 + ((locateKuartil1 - (lowerBound1Index > 0 ? frequencyCummulative[lowerBound1Index - 1] : 0)) / frequency[lowerBound1Index]) * p;
    kuartilResults[1] = lowerBound2 + ((locateKuartil2 - (lowerBound2Index > 0 ? frequencyCummulative[lowerBound2Index - 1] : 0)) / frequency[lowerBound2Index]) * p;
    kuartilResults[2] = lowerBound3 + ((locateKuartil3 - (lowerBound3Index > 0 ? frequencyCummulative[lowerBound3Index - 1] : 0)) / frequency[lowerBound3Index]) * p;

    return kuartilResults;
}
