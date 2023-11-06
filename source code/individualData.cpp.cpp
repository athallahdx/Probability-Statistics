#include "indvidualData.h"
#include <iostream>
#include <vector>
#include <cmath>


individual_data::individual_data(){
    system("cls");
	int n;
	int temp;
    system("cls");
    std::cout << "OLAH DATA TUNGGAL\n";
    std::cout << "=============================\n";
	std::cout << "Masuknya banyaknya data tunggal: ";
	std::cin >> n;

	for(int i=0 ; i<n ; i++){
		std::cout<<"Masukkan data tunggal sebanyak " << n << ": ";
		std::cin>>temp;
		data.push_back(temp);
	}
    dataSort();
    system("cls");
}

int individual_data::getUserOption(){
    int input;
    std::cout << "APA YANG INGIN DICARI ?" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "1. Modus                5. Desil                   9. Standar Deviasi" << std::endl;
    std::cout << "2. Rata-Rata            6. Range(Jangkauan)        10. EXIT" << std::endl;
    std::cout << "3. Median               7. Simpangan Rata-Rata"<< std::endl;
    std::cout << "4. Kuartil              8. Ragam(Variansi)" << std::endl;  
    std::cout << "===========================" << std::endl;
    std::cout << "Masukkan opsi [1-10]: ";
    std::cin >> input;

    return input;
}

void individual_data::loopMenu(){
    int userOption = 0;
    char is_continue;
    enum option{MODE=1, MEAN, MEDIAN, KUARTIL, DESIL, RANGE, MEAN_DEVIATION, VARIANCE, STANDARD_DEVIATION, EXIT};

    do {
        show_Individual_Data();
        userOption = getUserOption();

        switch (userOption) {
            case MODE: {
               findMode();
                break;
            }

            case MEAN: {
               findMean();
                break;
            }

            case MEDIAN: {
               findMedian();
                break;
            }

            case KUARTIL: {
               findQuartil();
                break;
            }

            case DESIL: {
               findDesil();
                break;
            }

            case RANGE: {
                findRange();
                break;
            }

            case MEAN_DEVIATION: {
				findMeanDeviation();
                break;
            }

            case VARIANCE: {
              findVariance();
                break;
            }

            case STANDARD_DEVIATION: {
				findStandardDeviation();
                break;
            }

            case EXIT: {
                std::cout << "Exiting the Data Individual" << std::endl;
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
    } while (userOption != EXIT);
}

double individual_data::findMedian(){
    int size=data.size();
    double median;
    if(size%2 == 1){
        median=data[(size+1)/2];
    } else{
        median=(data[size/2]+data[(size/2)+1])/2;
    }
     std::cout<<"\nMedian dari data tersebut adalah: "<< median << std::endl;
    return median;
}

void individual_data::dataSort() {
    for (int i = 0; i < data.size() - 1; i++) {
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void individual_data::show_Individual_Data(){
    std::cout<<"\nSORTED DATA: ";
	for(int i=0;i<data.size();i++){
		std::cout << data[i] << " ";
	}
   std:: cout << std::endl << std::endl;
}

void individual_data::findMode() {
    int modus = data[0];
    int totalMuncul = 1;

    for (int i = 0; i < data.size(); i++) {
        int muncul = 1;

        for (int j = i + 1; j < data.size(); j++) {
            if (data[i] == data[j]) {
                muncul++;
            }
        }

        if (muncul > totalMuncul) {
            totalMuncul = muncul;
            modus = data[i];
        }
    }
    if(totalMuncul==1){
        std::cout << "\nTidak Ada Modus" << std::endl;
        std::cout << "Jumlah Kemunculan Semua Elemen Sama" << std::endl;
    }else{
	std::cout<<"Modus dari data tersebut adalah: "<< modus << std::endl;
	std::cout<<"Data " << modus << " muncul sebanyak " << totalMuncul <<  " kali" << std::endl;
    }
}

void individual_data::findRange() {
    int range=data[data.size()-1]-data[0];
    std::cout << "Range/Jangkauan Data: " << range << std::endl;
}

double individual_data::findMean(){
	double sum = 0;
		for(int i=0; i<data.size(); i++){
			sum+=data[i];
		}
			double mean=sum/data.size();
	std::cout<<"Rata-rata dari data tersebut adalah: " << mean << std::endl;
    return mean;
}

double individual_data::findMeanDeviation(){
    double mean=findMean();
    
    double sum=0;
    for(int i=0; i<data.size(); i++){
        sum+=abs(data[i]-mean);
    }
    
    int size=data.size();
    double meanDeviation=sum/size;
    std::cout << "Nilai Simpangan Rata-Rata: " << meanDeviation;
    return meanDeviation;
}

 double individual_data::findVariance(){
    int sum=0;
    double mean=findMean();
    for(int i=0; i<data.size(); i++){
        sum += pow((data[i]-mean), 2);
    }
    int size=data.size();
    double variance=sum/size;
    std::cout << "Nilai Ragam(Variansi): " << variance;
    return variance;
 }

double individual_data::findStandardDeviation(){
    double variance=findVariance();
    double standardDeviation=sqrt(variance);
      std::cout << "\nNilai Standar Deviasi: " << standardDeviation;
    return standardDeviation;
}

void individual_data::findQuartil(){
	int q1,q2,q3;
	int size= data.size();
	int middle = size/2;
	q2 = (size % 2 ==0) ? (data[middle - 1] + data[middle]) / 2 : data[middle];
	int akhirBawah = middle;
	int awalAtas = (size % 2 == 0) ? middle: middle + 1;
	
	q1 = (akhirBawah % 2 == 0) ? (data[akhirBawah / 2 + 1] + data[akhirBawah / 2]) / 2 : data[akhirBawah / 2];
	q3 = (awalAtas % 2 ==0) ? (data[awalAtas + (size - awalAtas) / 2 - 1] + data[awalAtas + (size - awalAtas) / 2]) /2 : data[awalAtas + (size - awalAtas) / 2];
	int interQuartileRange=q3-q1;
    int quartileDeviation=0.5 * (q3-q1);

	std::cout<<"Quartil pertama: " << q1 <<std::endl;
	std::cout<<"Quartil kedua: " << q2 <<std::endl;
	std::cout<<"Quartil ketiga: "<< q3 <<std::endl;
    std::cout<<"Jangkauan Antar Kuartil: "<< interQuartileRange <<std::endl;
    std::cout<<"Simpangan Kuartil: "<< quartileDeviation << std::endl;
}

void individual_data::findDesil() {
    double desiles[10];
	int size=data.size();
    int k = size / 10;

    for (int i = 0; i < 10; i++) {
        if (size % 10 == 0) {
            desiles[i] = data[k * (i + 1) - 1];
        } else {
            int lower = k * i;
            int upper = k * (i + 1);
            double fraction = (size % 10) * 0.1;
            desiles[i] = data[lower] + (data[upper] - data[lower]) * fraction;
        }
        std::cout << "Desil " << i + 1 << ": " << desiles[i] << std::endl;
    }
    
}