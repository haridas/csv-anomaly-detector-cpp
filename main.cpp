#include<iostream>
#include<assert.h>

#include "histogram.h"
#include "csvreader.h"
#include "binselector.h"
#include "anomalydetector.h"

using namespace std;


//template<typename T>
void printColumnVector(std::vector<std::string> vector) {
    for(std::vector<string>::iterator iter = vector.begin(); iter != vector.end(); iter ++) {
        std::cout << *iter  << std::endl;
    }
}

void printMeanHist(std::vector<float> vector) {
    for(std::vector<float>::iterator iter = vector.begin(); iter != vector.end(); iter ++) {
        std::cout << *iter << " - ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    if(argc != 2) {
        std::cout << "Pass the csv file as first argument." << std::endl;
        std::abort();
    }

    CSVReader *csvReader = new CSVReader();
    csvReader->read(argv[1]);

    // Check column data.
    std::cout << " #Columns: " << csvReader->getColumnCount() << " #rows: " << csvReader->getRowCount() << std::endl;
    assert(csvReader->getColumnCount() == 4 && csvReader->getRowCount() == 6);

    // Check the column data reading.
    for (int i = 0; i < csvReader->getColumnCount(); i++) {
        std::vector<std::string> columnData = csvReader->getColumnData(i);
        assert (columnData.size() == csvReader->getRowCount());
    }

    // Histogram bin selector checks.
    Histogram *histogram = new Histogram();

    std::vector<BIN_SELECTOR> binSelector;
    binSelector.push_back(ALPHA_LOWER);
    binSelector.push_back(ALPHA_UPPER);
    binSelector.push_back(SPACE);
    histogram->setBinSelectors(binSelector);

    histogram->addTobin("Haridas 12");
    histogram->prettyPrintBinValues();
    std::vector<float> binValues = histogram->getBinValues();
//    assert (binValues[0] == 2 && binValues[1] == 6 && binValues[2] == 1);

    // normalize test
    histogram->normalize();
    histogram->prettyPrintNormalizedBinValues();
    binValues = histogram->getNormalizedBinValues();
//    assert (binValues[0] == 0.2 && binValues[1] == 0.6 && binValues[2] == 0.1 && binValues[4] == 0.1);



    /**
      * AnomalyDetector Class test cases.
      */

    // Get column histograms;
    std::vector<std::string> col1 = csvReader->getColumnData(0);
    std::vector<Histogram> hists1;
    std::vector<BIN_SELECTOR> select1;
    select1.push_back(ALPHA_LOWER);
    select1.push_back(ALPHA_UPPER);
    select1.push_back(DIGIT);
    select1.push_back(SPACE);
    for(std::vector<std::string>::iterator iter = col1.begin();
        iter != col1.end(); iter++) {
        Histogram *hist = new Histogram();
        hist->setBinSelectors(select1);
        hist->addTobin(*iter);
        hist->normalize();
        hists1.push_back(*hist);
    }

    // Pass the histograms to anomaly detector to identify problems.
    AnomalyDetector *anomalyDetector = new AnomalyDetector(hists1);
    printMeanHist(anomalyDetector->getMeanHistogram());
    anomalyDetector->findAnomalies();

    anomalyDetector->prettyPrintEuclidianDistanceVector();
    // Check column histogram.
    return 0;
}






