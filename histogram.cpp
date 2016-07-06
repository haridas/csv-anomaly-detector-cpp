
#include "histogram.h"

Histogram::Histogram(){

}

void Histogram::setBinSelectors(std::vector<BIN_SELECTOR> binMachers) {
    this->binSelectors = binMachers;
}

void Histogram::addTobin(std::string value) {
    for(std::string::iterator iter = value.begin(); iter != value.end(); iter++) {

        for(std::vector<BIN_SELECTOR>::iterator binIter = this->binSelectors.begin();
            binIter != this->binSelectors.end(); binIter++) {
//            std::cout << "Matching: " << *iter << " with bin: " << *binIter << std::endl;
            switch (*binIter) {
            case ALPHA_LOWER:
                if (std::islower(*iter))
                    this->binValues[ALPHA_LOWER] ++;
                break;
            case ALPHA_UPPER:
                if (std::isupper(*iter))
                    this->binValues[ALPHA_UPPER] ++;
                break;
            case DIGIT:
                if (std::isdigit(*iter))
                    this->binValues[DIGIT] ++;
                break;
            case AT_CHAR:
                if (*iter == '@')
                    this->binValues[AT_CHAR] ++;
                break;
            case SEMI_COLON:
                if(*iter == ';')
                    this->binValues[SEMI_COLON] ++;
                break;
            case SPACE:
                if(*iter == ' ')
                    this->binValues[SPACE] ++;
                break;
            case COLON:
                if(*iter == ':')
                    this->binValues[COLON] ++;
                break;
            default:
                std::cout << "Failed to find bin for char: " << *iter << std::endl;
                break;
            }
        }
    }
}

float Histogram::getMean() {

}

void Histogram::normalize() {

}

void Histogram::prettyPrintBin(std::vector<float> bin) {
    for(std::vector<float>::iterator iter = bin.begin(); iter != bin.end(); iter++) {
        std::cout << *iter << " - ";
    }
    std::cout << std::endl;
}

void Histogram::prettyPrintBinValues() {
    this->prettyPrintBin(this->binValues);
}

void Histogram::prettyPrintNormalizedBinValues() {
    this->prettyPrintBin(this->normalizedBinValues);
}

std::vector<float> Histogram::getBinValues() {
    return this->binValues;
}

std::vector<float> Histogram::getNormalizedBinValues() {
    return this->normalizedBinValues;
}
