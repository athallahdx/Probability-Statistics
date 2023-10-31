#include <iostream>
#include "groupedData.h"

int main(){
    grouped_data data_kelompok;
    data_kelompok.get_Grouped_Data();
    data_kelompok.get_frequency_cummulative();
    data_kelompok.get_classInterval();
    system("cls");
    data_kelompok.loopMenu();

    return 0;
}