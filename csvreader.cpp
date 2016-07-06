#include "csvreader.h"

CSVReader::CSVReader(){

}

void CSVReader::read(std::string fileName) {
    this->csvFile = fileName;
    this->fileStream = std::ifstream(fileName);

    this->refreshStream(this->fileStream);
}

int CSVReader::getColumnCount() {
    return 0;
}

std::vector<std::string> CSVReader::getColumnData(int index) {

}

void CSVReader::refreshStream(std::ifstream &csvFileStream) {

    // Reset the stream first.
    csvFileStream.clear();
    csvFileStream.seekg(0, std::ios::beg);


    std::string line;
    std::getline(csvFileStream, line);

    std::cout << "Skiped csv header: " << line.length() << std::endl;

}
