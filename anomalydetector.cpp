
#include "anomalydetector.h"

AnomalyDetector::AnomalyDetector()
{

}

AnomalyDetector::AnomalyDetector(std::vector<Histogram> histograms){
    this->histograms = histograms;
    this->findMeanHistogram();
}

void AnomalyDetector::findMeanHistogram() {
    std::vector<float> temp;
    for(std::vector<Histogram>::iterator iter = this->histograms.begin();
        iter != this->histograms.end(); iter++){
        std::transform (this->meanHistogram.begin(), this->meanHistogram.end(),
                        iter->getNormalizedBinValues().begin(), this->meanHistogram.begin(), std::plus<float>());
    }

    std::transform(this->meanHistogram.begin(), this->meanHistogram.end(),
                   this->meanHistogram.begin(),std::bind2nd(std::divides<float>(), this->histograms.size()));
}


float AnomalyDetector::findEuclidianDistance(std::vector<float> a, std::vector<float> b) {
    float squre = 0;
    for(int i =0; i < a.size(); i++){
        squre += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return std::sqrt(squre);
}

void AnomalyDetector::findAnomalies() {
    // Find the euclidian distance vector
    // Sort and pick the rows with anomaly.

    for(int i = 0; i < this->histograms.size(); i++){
        std::tuple<int, float> distance = std::tuple<int, float>(i,
                                         this->findEuclidianDistance(
                                             this->histograms[i].getNormalizedBinValues(),
                                                                        this->meanHistogram));
        this->euclidianDistanceVector.push_back(distance);
    }


    // Sort and pick the rows which are anomaly.

//    std::sort(std::begin(this->euclidianDistanceVector), std::end(this->euclidianDistanceVector),
//              [](auto const &t1, auto const &t2) {
//                    return get<1>(t1) < get<1>(t2); // or use a custom compare function
//               }
//    );

}

std::vector<std::tuple<int, float> > AnomalyDetector::getAnomalies() {
    return this->euclidianDistanceVector;
}

void AnomalyDetector::prettyPrintEuclidianDistanceVector() {
    for(std::vector<std::tuple<int, float>>::iterator iter = this->euclidianDistanceVector.begin();
        iter != this->euclidianDistanceVector.end(); iter++) {
        std::cout << "Row: " << std::get<0>(*iter) << " Distance from Mean: " << std::get<1>(*iter) << std::endl;
    }
}

void AnomalyDetector::prettyPrintAnomalyVector() {
    for(std::vector<bool>::iterator iter = this->anomalyVector.begin();
        iter != this->anomalyVector.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}




