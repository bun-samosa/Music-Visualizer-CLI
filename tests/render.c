#include "../include/render/render.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    setbuf(stdout, NULL);
    int bars[32];

    srand(time(NULL));

    for (int frame = 0; frame<200; frame++) {
        for (int i = 0; i < 32; i++) {
            bars[i] = rand() % (21);
        }
        render_bars(bars, 32, 20);
        usleep(16000);
    }
    return 0;
}