#include "../../include/color/color.h"

const char* get_bar_color(int value) {
    (void)value; // to suppress unused parameter warning
    return "\033[1;37m"; // White
}