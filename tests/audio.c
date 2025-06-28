#include "../include/audio/audio.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    init_audio();

    int16_t buffer[1024];

    for (int i = 0; i < 10; i++) {
        get_audio_samples(buffer, 1024);

        long sum = 0;
        for (int j = 0; j < 1024; j++) {
            sum += buffer[j];
        }

        printf("Avg sample value: %ld\n", sum / 1024);
    }

    cleanup_audio();
    return 0;
}