#include "ClickHal.hpp"
#include <fstream>
#include <iostream>

ClickHal::ClickHal() {}

bool ClickHal::triggerClick() {
    std::ofstream triggerFile(triggerPath);
    if (!triggerFile) {
        std::cerr << "Error: Can't open trigger for writing\n";
        return false;
    }
    triggerFile << "1";
    return true;
}

int ClickHal::readValue() {
    std::ifstream valueFile(valuePath);
    int val = -1;
    if (valueFile) {
        valueFile >> val;
    } else {
        std::cerr << "Error: Can't open value for reading\n";
    }
    return val;
}
