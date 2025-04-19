#include "ClickHal.hpp"
#include <unistd.h>

int main() {
    ClickHal hal;

    hal.triggerClick();
    sleep(1);

    hal.readValue();
    return 0;
}
