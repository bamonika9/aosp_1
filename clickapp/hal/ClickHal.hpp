#pragma once
#include <string>

class ClickHal {
public:
    ClickHal();
    bool triggerClick();
    int readValue();
private:
    const std::string triggerPath = "/sys/kernel/click/trigger";
    const std::string valuePath = "/sys/kernel/click/value";
};
