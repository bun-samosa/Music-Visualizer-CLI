#include "../../include/config/config.h"

// Can be changed ...

Config default_config() {
    Config c;

    c.bar_count = 48;
    c.max_height = 20;
    c.refresh_rate = 60;
    c.smoothing = 0.5f;

    return c;
}
