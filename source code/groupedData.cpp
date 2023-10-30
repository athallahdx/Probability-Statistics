#include <iostream>
#include <vector>
#include "groupedData.h"

void grouped_data::get_Grouped_Data(){
    int row;
    int lowerBound;
    int upperBound;
    int freq;

    std::cout << "Berapa banyak baris data ? : ";
    std::cin >> row;
    for(int i=0; i<row; i++){
        std::cout << "Masukkan data baris ke-" << i+1 << ": ";
        std::cin >> lowerBound >> upperBound;
        std::cout << "Masukkan frekuensi baris tersebut: ";
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
        std::cout << "______________________________\n";
}

/*double grouped_data::findMode(const std::vector<std::vector<int>>){

}*/
