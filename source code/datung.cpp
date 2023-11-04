#include <iostream>
#include <cmath>
using namespace std;


void showArray(int array[], int size){
    cout<<"data yang sudah diurutkan: ";
	for(int i=0;i<size;i++) cout<<array[i]<<" ";
	cout<<endl;
	int max = array[size-1];
	int min = array[0];
	int range = max-min;
	printf("Nilai maksimal data adalah: %d\nNilai minimal data adalah: %d\nJangkauan data adalah: %d\n",max,min,range);
}

void insertArray(int array[], int size){
	for(int i=0;i<size;i++){
		cout<<"masukkan data ke-"<<i+1<<": ";
		cin>>array[i];
	}
}

void arraySort(int array[], int size){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			  if (array[j] > array[j + 1]) {
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
      }
    }
  }
}

void modus(int array[], int size) {
    int modus = array[0];
    int totalMuncul = 1;

    for (int i = 0; i < size; i++) {
        int muncul = 1;

        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                muncul++;
            }
        }

        if (muncul > totalMuncul) {
            totalMuncul = muncul;
            modus = array[i];
        }
    }
	cout<<"Modus dari data tersebut adalah: "<<modus<<endl;
	printf("data %d muncul sebanyak %d kali",modus,totalMuncul);
}


void mean(int array[],int size){
	double sum = 0;
	for(int i=0;i<size;i++) sum+=array[i];
	double mean=sum/size;
	double selisih = 0;
	for(int i=0;i<size;i++) selisih+=abs(array[i]-mean);
	double simpangRata = selisih/size;
	double variansi = pow(selisih,2)/size;
	double deviasi = sqrt(variansi);
	cout<<"Rata-rata dari data tersebut adalah: "<<mean<<endl;
	cout<<"Simpangan rata-rata dari data tersebut adalah: "<<simpangRata<<endl;
	cout<<"Variansi data tersebut adalah: "<<variansi<<endl;
	cout<<"Standar Deviasi dari data tersebut adalah: "<<deviasi<<endl;
	
}

void quartil(int array[],int size){
	int q1,q2,q3;
	int middle = size/2;
	q2 = (size % 2 ==0) ? (array[middle - 1] + array[middle]) / 2 : array[middle];
	int akhirBawah = middle;
	int awalAtas = (size % 2 == 0) ? middle: middle + 1;
	
	q1 = (akhirBawah % 2 == 0) ? (array[akhirBawah / 2 + 1] + array[akhirBawah / 2]) / 2 : array[akhirBawah / 2];
	q3 = (awalAtas % 2 ==0) ? (array[awalAtas + (size - awalAtas) / 2 - 1] + array[awalAtas + (size - awalAtas) / 2]) /2 : array[awalAtas + (size - awalAtas) / 2];
	int qrange = q3-q1;
	int simpanganQ = qrange / 2;
	cout<<"Kuartil pertama: "<<q1<<endl;
	cout<<"Kuartil kedua: "<<q2<<endl;
	cout<<"Kuartil ketiga: "<<q3<<endl;
	cout<<"Jangkauan Interkuartil: "<<qrange<<endl;
	cout<<"Simpangan interkuartil: "<<simpanganQ<<endl;
}

void desil(int array[], int size) {
    double desiles[10];
    int k = size / 10;

    for (int i = 0; i < 10; i++) {
        if (size % 10 == 0) {
            desiles[i] = array[k * (i + 1) - 1];
        } else {
            int lower = k * i;
            int upper = k * (i + 1);
            double fraction = (size % 10) * 0.1;
            desiles[i] = array[lower] + (array[upper] - array[lower]) * fraction;
        }
        cout << "Desil " << i + 1 << ": " << desiles[i] << endl;
    }
}

int main(){
	int sizeArray;
	cout<<"masukkan banyaknya data: ";
	cin>>sizeArray;
	int dataArray[sizeArray];
	insertArray(dataArray,sizeArray);
	arraySort(dataArray,sizeArray);
	//cls taro sini
	showArray(dataArray,sizeArray);
	int choice;
	cout<<"Pilihan pengolahan data:"<<endl;
	cout<<"1. Modus"<<endl;
	cout<<"2. Mean(Rata-rata)"<<endl;
	cout<<"3. Quartil"<<endl;
	cout<<"4. Desil"<<endl;
	cout<<"Pilih: ";
	cin>>choice;
	
	switch (choice){
		case 1: 
			modus(dataArray,sizeArray);
			break;
		case 2: 
			mean(dataArray,sizeArray);
			break;
		case 3: 
			quartil(dataArray,sizeArray);
			break;
		case 4: 
			desil(dataArray,sizeArray);
			break;
		default:
			cout<<"Pilihan tidak valid."<<endl;	
	}
	//mean(dataArray,sizeArray);
	//modus(dataArray,sizeArray);
	//quartil(dataArray,sizeArray);
	//desil(dataArray,sizeArray);
	
	return 0;
}
