#ifndef ANOMALYDETECTOR_H
#define ANOMALYDETECTOR_H

#include<iostream>
#include<vector>
#include<math.h>
#include<tuple>

#include "histogram.h"

/**
 * @brief The AnomalyDetector class
 *
 *        Histogram based anomaly detector implementation.
 *
 *
 * TODO: Checkout more sophisticated distance methods from
 *       http://www.ariel.ac.il/sites/ofirpele/publications/ECCV2010.pdf
 *
 */

class AnomalyDetector
{
    std::vector<Histogram> histograms;

    // TODO: make Histogram class more generic.
    std::vector<float> meanHistogram = std::vector<float>(BIN_SELECTOR_SIZE, 0);

    // Percentile of rows need to be reported.
    int ANOMALY_THRESHOLD = 1;

    // A single dimention vector to flag a cell has anomaly or not.
    std::vector<bool> anomalyVector;

    // Vector keeps track of the distance vector after compare
    // it with mean histogram, Format - (histgramId, distance)
    // Helpful to itentify which histograms are outlier.
    std::vector<std::tuple<int, float>> euclidianDistanceVector;

    // From the list of histograms, get the mean histogram.
    void findMeanHistogram();

    /**
     * @brief findEuclidianDistance
     * Find distnace for two points, in our case we are checking only for
     * one dimention values as we are using normalized histograms.
     * @return float
     */
    float findEuclidianDistance(float, float);

public:
    AnomalyDetector();
    AnomalyDetector(std::vector<Histogram> histograms);

    void setAnomalyThreshold(int percentile);

    // Report the anomaly of a csv cell, with (raw, column) index ( zero indexed ).
    Anomalies getAnomalies();

    std::vector<bool> getAnomalyVector();

    std::vector<float> getMeanHistogram() {
        return this->meanHistogram;
    }

};

#endif // ANOMALYDETECTOR_H
