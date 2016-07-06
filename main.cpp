#include<iostream>
#include<assert.h>

#include "histogram.h"
#include "csvreader.h"
#include "binselector.h"

using namespace std;


//template<typename T>
void printColumnVector(std::vector<std::string> vector) {
    for(std::vector<string>::iterator iter = vector.begin(); iter != vector.end(); iter ++) {
        std::cout << *iter  << std::endl;
    }
}

int main(int argc, char** argv)
{
    if(argc != 2) {
        std::cout << "Pass the csv file as first argument." << std::endl;
        std::abort();
    }

    CSVReader *csvReader = new CSVReader();
    csvReader->read("/home/haridas/projects/personal/gitlap/csv-anomaly-detector/data.csv");


    // Check column data.
    std::cout << " #Columns: " << csvReader->getColumnCount() << " #rows: " << csvReader->getRowCount() << std::endl;

    // Check the column data reading.
    for (int i = 0; i < csvReader->getColumnCount(); i++) {
        std::vector<std::string> columnData = csvReader->getColumnData(i);
        assert (columnData.size() == csvReader->getRowCount());
//        printColumnVector(columnData);
    }

    // Histogram bin selector checks.
    Histogram *histogram = new Histogram();

    std::vector<BIN_SELECTOR> binSelector;
    binSelector.push_back(ALPHA_LOWER);
    binSelector.push_back(ALPHA_UPPER);
    binSelector.push_back(DIGIT);
    binSelector.push_back(SPACE);
    histogram->setBinSelectors(binSelector);

    histogram->addTobin("Haridas 12");
    histogram->prettyPrintBinValues();
    std::vector<float> binValues = histogram->getBinValues();
    assert (binValues[0] == 2 && binValues[1] == 6 && binValues[2] == 1 && binValues[4] == 1);

    // Check column histogram.
    return 0;
}






