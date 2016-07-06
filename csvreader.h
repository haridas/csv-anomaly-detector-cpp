#ifndef CSVREADER_H
#define CSVREADER_H

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>

/**
 * @brief The CSVReader class
 *
 * Read CSV and keep it in a file stream, and provide all
 * utility methods required to find rows with anomaly.
 */

class CSVReader
{
    std::string csvFile = "";
    int numColumns = 0;
    int numRows = 0;

    // Don't dump all data into RAM.
    std::ifstream fileStream;

    void setColumnCount();
    void setRowCount();
public:
    CSVReader();
    int getColumnCount();
    int getRowCount();

    void read(std::string fileName);

    /**
     * @brief getColumnData Get the column vector of the csv file excluding csv header.
     *        The index start from 0.
     * @return std::vector<std::string>
     */
    std::vector<std::string> getColumnData(int index);

    /**
     * @brief refreshStream Skip the csv header and reset the stream to first row.
     * @param csvFileStream
     */
    void refreshStream(std::ifstream &csvFileStream);
};

#endif // CSVREADER_H
