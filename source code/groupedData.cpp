#include <iostream>
#include <vector>
#include <cmath> 
#include "groupedData.h"


grouped_data::grouped_data(){
    int row;
    int lowerBound;
    int upperBound;
    int freq;
    system("cls");
    std::cout << "OLAH DATA KELOMPOK\n";
    std::cout << "=============================\n";
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
    get_frequency_cummulative();
    get_classInterval();
    system("cls");
}

void grouped_data::get_frequency_cummulative(){
    int temp = 0;

    for(int i = 0; i < frequency.size(); i++){
        temp += frequency[i];
        frequencyCummulative.push_back(temp); 
    }
}

void grouped_data::get_classInterval(){
    classInterval=(data[0].second-data[0].first)+1;
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

int grouped_data::getUserOption() {
    int input;
    std::cout << "APA YANG INGIN DICARI ?" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "1. Modus                5. Desil                   9. Simpangan Kuartil" << std::endl;
    std::cout << "2. Rata-Rata            6. Persentil               10. Simpangan Rata-Rata" << std::endl;
    std::cout << "3. Median               7. Range(Jangkauan)        11. Ragam(Variansi)" << std::endl;
    std::cout << "4. Kuartil              8. Jangkauan antarkuartil  12. Standar Deviasi" << std::endl;
    std::cout << "13. Exit" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Masukkan opsi [1-13]: ";
    std::cin >> input;

    return input;
}

void grouped_data::loopMenu(){
    int userOption = 0;
    char is_continue;
    enum option{MODE=1, MEAN, MEDIAN, KUARTIL, DESIL, PERSENTIL, RANGE, INTER_QUARTILE_RANGE, QUARTILE_DEVIATION, MEAN_DEVIATION, VARIANCE, STANDARD_DEVIATION, EXIT};
    
    while (userOption != EXIT) {
        show_Grouped_Data();
        userOption = getUserOption();
        
        switch (userOption) {
            case MODE: {
                double mode = findMode();
                std::cout << "\nModus Data Kelompok: " << mode << std::endl;
                break;
            }

            case MEAN: {
                double mean = findMean();
                std::cout << "Mean Data Kelompok: " << mean;
                break;
            }

            case MEDIAN: {
                double median = findMedian();
                std::cout << "\nMedian Data Kelompok: " << median << std::endl;
                break;
            }

            case KUARTIL: {
                double* kuartils = findKuartil();
                for (int i = 0; i < 3; i++) {
                    std::cout << "Kuartil " << i + 1 << ": " << kuartils[i] << std::endl;
                }
                delete[] kuartils;
                break;
            }

            case DESIL: {
                int find;
                std::cout << "Desil Ke-Berapa: ";
                std::cin >> find;
                double desil = findDesil(find);
                std::cout << "Desil Ke-" << find << ": " << desil << std::endl;
                break;
            }

            case PERSENTIL: {
                int find;
                std::cout << "Persentil Ke-Berapa: ";
                std::cin >> find;
                double persentil = findPersentil(find);
                std::cout << "Persentil Ke-" << find << ": " << persentil << std::endl;
                break;
            }

            case RANGE: {
                double range=findRange();
                std::cout << "Jangkauan(range): " << range << std::endl;
                break;
            }

            case INTER_QUARTILE_RANGE: {
                double interQuartileRange = findInterQuartileRange();
                std::cout << "Nilai Jangkauan antarkuartil: " << interQuartileRange << std::endl;
                break;
            }

            case QUARTILE_DEVIATION: {
                double quartileDeviation = findQuartileDeviation();
                std::cout << "Nilai Simpangan Kuartil: " << quartileDeviation << std::endl;
                break;
            }

            case MEAN_DEVIATION: {
                double meanDeviation = findMeanDeviation();
                std::cout << "Nilai Simpangan rata-rata: " << meanDeviation << std::endl;
                break;
            }

            case VARIANCE: {
                double variance = findVariance();
                std::cout << "Nilai Ragam(Variansi): " << variance << std::endl;
                break;
            }

            case STANDARD_DEVIATION: {
                double standardDeviation = findStandardDeviation();
                std::cout << "Nilai Standar Deviasi: " << standardDeviation << std::endl;
                break;
            }

            case EXIT: {
                std::cout << "Exiting the Data Kelompok" << std::endl;
                std::cin.get(); 
                std::cin.ignore();
                break;
            }

            default:
                std::cout << "Invalid option. Please select an option from 1 to 13." << std::endl;
                std::cin.get(); 
                std::cin.ignore();
        }
        std::cin.get();
        std::cin.ignore();
        system("cls");
    }
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

double grouped_data::findDesil(int desilN){
    int totalFrequency = frequencyCummulative.back();
    double locateDesil=(desilN/10.0)*totalFrequency;
    int row=0;
    for(row = 0; row < frequencyCummulative.size(); row++){
        if(frequencyCummulative[row]>=locateDesil){
            break;
       }
    }

    double lowerBound=data[row].first-0.5;
    double desilResult=lowerBound+ ((locateDesil-frequencyCummulative[row-1])/frequency[row])*classInterval;

    return desilResult;
}

double grouped_data::findPersentil(int persentilN){
    int totalFrequency = frequencyCummulative.back();
    double locatePersentil=(persentilN/100.0)*totalFrequency;
    int row=0;
    for(row = 0; row < frequencyCummulative.size(); row++){
        if(frequencyCummulative[row]>=locatePersentil){
            break;
       }
    }

    double lowerBound=data[row].first-0.5;
    double persentilResult=lowerBound+ ((locatePersentil-frequencyCummulative[row-1])/frequency[row])*classInterval;

    return persentilResult;
}

double grouped_data::findInterQuartileRange(){
    double* kuartils = findKuartil();
    double interQuartileRange=kuartils[2]-kuartils[0];
    delete[] kuartils;
    return interQuartileRange;
}

double grouped_data::findRange(){
    double range=data[data.size() - 1].second-data[0].first;
    return range;
}

double grouped_data::findQuartileDeviation(){
    double interQuartileRange=findInterQuartileRange();
    double quartileDeviation=0.5 * interQuartileRange;
    return quartileDeviation;
}

double grouped_data::findMeanDeviation(){
    double mean=findMean();
    std::vector<double> xi;
    double temp;
    for(int i=0; i<data.size(); i++){
        temp=(data[i].first+data[i].second)/2;
        xi.push_back(temp);
    }

    double sum=0;
    for(int i=0; i<data.size(); i++){
        sum+=(frequency[i]*abs(xi[i]-mean));
    }
    
    double meanDeviation=sum/frequencyCummulative[frequencyCummulative.size()-1];
    return meanDeviation;
}

double grouped_data::findVariance(){
    double mean=findMean();
    std::vector<double> xi;
    double temp;
    for(int i=0; i<data.size(); i++){
        temp=(data[i].first+data[i].second)/2;
        xi.push_back(temp);
    }
    double sum=0;
    for(int i=0; i<data.size(); i++){
        sum+=(frequency[i]*pow((xi[i]-mean), 2));
    }
    
    double variance=sum/frequencyCummulative[frequencyCummulative.size()-1];
    return variance;
}

double grouped_data::findStandardDeviation(){
    double variance=findVariance();
    double standardDeviation=sqrt(variance);
    return standardDeviation;
}