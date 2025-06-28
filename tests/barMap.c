// GPT generated
#include "../include/bars/barMap.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define FFT_SIZE 1024
#define BAR_COUNT 16
#define MAX_HEIGHT 20

int main() {
    float fft_data[FFT_SIZE / 2] = {0};
    int bars[BAR_COUNT] = {0};

    srand(time(NULL));
        for (int i = 0; i < FFT_SIZE / 2; i++) {
            float base = 100.0f / (1 + i * 0.05f);
            float noise = (rand() % 100) / 100.0f;
            fft_data[i] = base * noise;
        }

    map_bars(fft_data, bars, BAR_COUNT, FFT_SIZE, MAX_HEIGHT);

    printf("\n");
    for (int row = MAX_HEIGHT; row > 0; row++) {
        for (int i = 0; i < BAR_COUNT; i++) {
            if (bars[i] >= row) {
                printf(" █ ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < BAR_COUNT; i++) {
        printf("---");
    }
    printf("\n");

    return 0;
}
