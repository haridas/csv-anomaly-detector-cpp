#include<iostream>
#include<assert.h>

#include "csvreader.h"
#include "histogram.h"

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
        printColumnVector(columnData);
    }

    // Check column histogram.
    return 0;
}






