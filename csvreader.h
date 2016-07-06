#ifndef CSVREADER_H
#define CSVREADER_H

#include<iostream>
#include<vector>
#include<fstream>

class CSVReader
{
    std::string csvFile = "";
    int numColumns = 0;

    // Don't dump all data into RAM.
    std::ifstream fileStream;
public:
    CSVReader();
    int getColumnCount();

    void read(std::string fileName);

    /**
     * @brief getColumnData Get the column vector of the csv file excluding csv header.
     * @return
     */
    std::vector<std::string> getColumnData(int index);

    /**
     * @brief refreshStream Skip the csv header and reset the stream to first row.
     * @param csvFileStream
     */
    void refreshStream(std::ifstream &csvFileStream);
};

#endif // CSVREADER_H
