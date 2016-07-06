#include <iostream>
#include "csvreader.h"

using namespace std;

int main()
{
    CSVReader *csvReader = new CSVReader();
    csvReader->read("./data.csv");
    return 0;
}




