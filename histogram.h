#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include<iostream>
#include<algorithm>
#include<numeric>

#include "binselector.h"

/**
 * @brief The Histogram class
 *
 * Each csv data cell will have corresponding Histogram object
 * We use this to identify the column specific patterns.
 *
 * This histogram bin order will be same order as the binSelector.
 */

class Histogram
{
private:
    std::vector<BIN_SELECTOR> binSelectors;
    int numObservations;
    int numBins = BIN_SELECTOR_SIZE; // Same as number of @binSelectors length.

    // Initialize the histogram bins.
    std::vector<float> binValues = std::vector<float>(numBins, 0);
    std::vector<float> normalizedBinValues = std::vector<float>(numBins, 0);

    void prettyPrintBin(std::vector<float> bin);
public:
    Histogram();

    /**
     * @brief setBinSelectors Regex based bin selector for given data.
     *        Assumed that the given data only match with only one selector
     *        or nothing at all.
     * @param binMachers
     */
    void setBinSelectors(std::vector<BIN_SELECTOR> binMachers);


    /**
     * @brief addTobin Add a value under a Histogram bin.
     * @param value
     */
    void addTobin(std::string value);

    /**
     * @brief normalize Normalize the histogram to make it uniform for all cell.
     */
    void normalize();

    std::vector<float> getBinValues();
    std::vector<float> getNormalizedBinValues();

    void prettyPrintBinValues();
    void prettyPrintNormalizedBinValues();
};

#endif // HISTOGRAM_H
