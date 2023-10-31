#ifndef GROUPED_DATA
#define GROUPED_DATA
#include <vector>
#include <utility>

class grouped_data{
    public:
        std::vector<std::pair<int, int>> data;
        std::vector<int> frequency;
        std::vector<int> frequencyCummulative;
        int classInterval;

        void get_Grouped_Data();
        void get_frequency_cummulative();
        void get_classInterval();
        void show_Grouped_Data();
        double findMode();
        double findMean();
        double findMedian();
        double* findKuartil();
        double findDesil(int desilN);
        double findPersentil(int PersentilN);



};





#endif