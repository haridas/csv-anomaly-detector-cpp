#include <iostream>
#include "csvreader.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 2) {
        std::cout << "Pass the csv file as first argument." << std::endl;
        std::abort();
    }

    CSVReader *csvReader = new CSVReader();
    csvReader->read("/home/haridas/projects/personal/gitlap/csv-anomaly-detector/data.csv");
    std::cout << " #Columns: " + csvReader->getColumnCount() << std::endl;

    return 0;
}




