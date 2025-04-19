#include "ClickHal.hpp"
#include <unistd.h> // for sleep

int main() {
    ClickHal hal;

    hal.triggerClick();
    sleep(1); // Give the driver time if needed

    hal.readValue();
    return 0;
}
