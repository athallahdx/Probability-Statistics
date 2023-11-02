#include <iostream>
using namespace std;

void showArray(int array[], int size){
    cout<<"data yang sudah diurutkan: ";
	for(int i=0;i<size;i++) cout<<array[i]<<" ";
	cout<<endl;
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
	cout<<"Rata-rata dari data tersebut adalah: ";
}

void quartil(int array[],int size){
	int q1,q2,q3;
	int middle = size/2;
	q2 = (size % 2 ==0) ? (array[middle - 1] + array[middle]) / 2 : array[middle];
	int akhirBawah = middle;
	int awalAtas = (size % 2 == 0) ? middle: middle + 1;
	
	q1 = (akhirBawah % 2 == 0) ? (array[akhirBawah / 2 + 1] + array[akhirBawah / 2]) / 2 : array[akhirBawah / 2];
	q3 = (awalAtas % 2 ==0) ? (array[awalAtas + (size - awalAtas) / 2 - 1] + array[awalAtas + (size - awalAtas) / 2]) /2 : array[awalAtas + (size - awalAtas) / 2];
	
	cout<<"Quartil pertama: "<<q1<<endl;
	cout<<"Quartil kedua: "<<q2<<endl;
	cout<<"Quartil ketiga: "<<q3<<endl;
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
	showArray(dataArray,sizeArray);
	//mean(dataArray,sizeArray);
	//modus(dataArray,sizeArray);
	//quartil(dataArray,sizeArray);
	//desil(dataArray,sizeArray);
	
	return 0;
}