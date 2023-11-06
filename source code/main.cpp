#include <iostream>
#include "groupedData.h"
#include "Binomdist.h"
#include "indvidualData.h"

int menu();

int main(){
    
    enum option{DATA_TUNGGAL=1, DATA_KELOMPOK, BINOMIALDIST, EXIT};
    int userOption=0;

   while (userOption != EXIT) {
    userOption = menu();
        switch (userOption)
        {
        case DATA_TUNGGAL:{
            individual_data data_tunggal;
            data_tunggal.loopMenu();
            break;
            }
        case DATA_KELOMPOK:{
                grouped_data data_kelompok;
                data_kelompok.loopMenu();
            break;
            }
        case BINOMIALDIST:{ 
                Binomial_Distribution binomd;
                double binom=binomd.binomdist();
                std::cout << "Hasil probabilitas dalam bentuk riil: " << binom << std::endl;
                std::cin.get(); 
                std::cin.ignore();
            break;
            }
        default:{
            if(userOption!=4){
            std::cout << "pilihan tidak ditemukan!!!" << std::endl;
            break;
            }
            }
        }

   }

    std::cout << "\nAkhir dari program" << std::endl;

    std::cin.get();
    return 0;
}

// menu utama
int menu(){
    int input;
    system("cls");

    std::cout << "OLAH DATA PROBABILITAS DAN STATISTIKA" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "1. Data Tunggal" << std::endl;
    std::cout << "2. Data Kelompok" << std::endl;
    std::cout << "3. Probabilitas Binomial" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Pilih [1-4] : ";
    std::cin >> input;
    return input;
}

