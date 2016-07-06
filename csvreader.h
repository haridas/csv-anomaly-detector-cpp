#ifndef CSVREADER_H
#define CSVREADER_H

#include<iostream>
#include<vector>

class CSVReader
{
    std::string csvFile = "";
public:
    CSVReader();
    int getColumnCount();

    void read(std::string fileName);

    /**
     * @brief getColumnData Get the column vector of the csv file excluding csv header.
     * @return
     */
    std::vector<char*> getColumnData(int index);

};

#endif // CSVREADER_H
