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

        grouped_data();
        void show_Grouped_Data();
        void loopMenu();
        int getUserOption();

    private:
        void get_frequency_cummulative();
        void get_classInterval();
        double findMode();
        double findMean();
        double findMedian();
        double* findKuartil();
        double findDesil(int desilN);
        double findPersentil(int PersentilN);
        double findInterQuartileRange();
        double findRange();
        double findQuartileDeviation();
        double findMeanDeviation();
        double findVariance();
        double findStandardDeviation();

};





#endif

