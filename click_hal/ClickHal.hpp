#ifndef CLICK_HAL_HPP
#define CLICK_HAL_HPP

#include <string>

class ClickHal {
public:
    ClickHal(const std::string& triggerPath = "/sys/kernel/click/trigger",
             const std::string& valuePath = "/sys/kernel/click/value");

    bool triggerClick();
    int readValue();

};

#endif
