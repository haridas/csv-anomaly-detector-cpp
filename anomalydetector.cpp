
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

float AnomalyDetector::findEuclidianDistance(float a, float b) {
    return std::sqrt((a-b) * (a-b));
}




