#include "csvreader.h"

CSVReader::CSVReader(){

}

void CSVReader::read(std::string fileName) {
    this->csvFile = fileName;
    this->fileStream = std::ifstream(fileName);

    this->refreshStream(this->fileStream);
    this->setColumnCount();
    this->setRowCount();

}

void CSVReader::setColumnCount() {
    if(!this->fileStream) {
        std::cout << " Invalid csv filestream" << std::endl;
    } else {
        std::string line;
        std::getline(this->fileStream, line);
        if(line.length() > 0)
            this->numColumns = std::count(line.begin(), line.end(), ',') + 1;
    }
    // Reset the stream back.
    this->refreshStream(this->fileStream);
}

void CSVReader::setRowCount() {

    this->refreshStream(this->fileStream);
    if(!this->fileStream) {
        std::cout << " Invalid csv stream type" << std::endl;
    } else {
        std::string line;
        int count = 0;
        while(std::getline(this->fileStream, line)) {
            if (line.length() > 0)
                count ++;
        }
        this->numRows = count;
    }
}

int CSVReader::getColumnCount() {
    return this->numColumns;
}

int CSVReader::getRowCount() {
    return this->numRows;
}


std::vector<std::string> CSVReader::getColumnData(int index) {
    std::vector<std::string> columnData;
    this->refreshStream(this->fileStream);

    std::string line, cell;
    while(std::getline(this->fileStream, line)) {
        std::stringstream lineStream(line);
        int column = 0;
        while(std::getline(lineStream, cell, ',')) {
            if (index == column) {
                columnData.push_back(cell);
                break;
            }
            column ++;
        }
    }
    return columnData;
}

void CSVReader::refreshStream(std::ifstream &csvFileStream) {

    // Reset the stream first.
    csvFileStream.clear();
    csvFileStream.seekg(0, std::ios::beg);


    std::string line;
    std::getline(csvFileStream, line);

    std::cout << "Skiped csv header: " << line.length() << " Header: " << line << std::endl;

}
