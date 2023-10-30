#ifndef GROUPED_DATA
#define GROUPED_DATA
#include <vector>
#include <utility>

class grouped_data{
    public:
        std::vector<std::pair<int, int>> data;
        std::vector<int> frequency;

        void get_Grouped_Data();
        void show_Grouped_Data();
        double findMode();
        double findMean();
        double findMedian();
        double* kuartil();
        



};





#endif