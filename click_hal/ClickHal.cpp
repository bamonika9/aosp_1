#include "ClickHal.hpp"
#include <fstream>
#include <iostream>

ClickHal::ClickHal(const std::string& triggerPath, const std::string& valuePath)
    : triggerPath_(triggerPath), valuePath_(valuePath) {}

bool ClickHal::triggerClick() {
    std::ofstream triggerFile(triggerPath_);
    if (!triggerFile.is_open()) {
        std::cerr << "Error: Can't open " << triggerPath_ << " for writing\n";
        return false;
    }

    triggerFile << "1\n";
    triggerFile.close();
    std::cout << "Successfully triggered click!" << std::endl;
    return true;
}

int ClickHal::readValue() {
    std::ifstream valueFile(valuePath_);
    if (!valueFile.is_open()) {
        std::cerr << "Error: Can't open " << valuePath_ << " for reading\n";
        return -1;
    }

    int val = -1;
    valueFile >> val;
    valueFile.close();
    std::cout << "Value read: " << val << std::endl;
    return val;
}
