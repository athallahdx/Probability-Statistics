#ifndef INDIVIDUAL_DATA
#define INDIVIDUAL_DATA
#include <vector>
#include <utility>

class individual_data{
    public:
        std::vector<int> data;
        void loopMenu();
        individual_data();

    private:
        void show_Individual_Data();
        void dataSort();
        int getUserOption();
        double findMedian();
        double findMean();
        void findMode();
        void findDesil();
        void findQuartil();
        void findRange();
        double findMeanDeviation();
        double findVariance();
        double findStandardDeviation();
        
};






#endif