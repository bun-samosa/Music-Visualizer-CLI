#include "../../include/utils/utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int clamp(int value, int min, int max) {
    if (value < min) 
        return min;
    if (value > max) 
        return max;

    return value;
}

float map_range(float value, float in_min, float in_max, float out_min, float out_max) {
    if (in_max-in_min == 0.0f){
        return out_min;
    }
    float result = (((value-in_min)*(out_max-out_min)) / (in_max-in_min)) + out_min;
    return result;
}

void get_terminal_size(int *width, int *height) {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        if (width)  
            *width = w.ws_col;
        if (height) 
            *height = w.ws_row;
    } else {
        if (width)  
            *width = 80;
        if (height) 
            *height = 24;
    }
}

void* xmalloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "from src/utils/utility.c -> xmalloc(): failed to allocate %zu bytes: %s\n", size, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return ptr;
}