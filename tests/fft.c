#include "../include/audio/audio.h"
#include "../include/fft/fft.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    init_audio();
    int16_t raw_samples[1024];
    float float_samples[1024];
    float fft_output[1024/2 + 1];

    for (int frame = 0; frame < 20; ++frame) {
        if (get_audio_samples(raw_samples, 1024) != 0) {
            fprintf(stderr, "Failed to read audio samples.\n");
            break;
        }

        for (int i = 0; i < 1024; ++i) {
            float_samples[i] = raw_samples[i] / 32768.0f; // normalize [-1, 1]
        }

        compute_fft(float_samples, fft_output, 1024);

        int peak_index = 0;
        float peak_value = 0.0f;

        for (int i = 1; i < 1024/2 + 1; ++i) {
            if (fft_output[i] > peak_value) {
                peak_value = fft_output[i];
                peak_index = i;
            }
        }

        float frequency = (float)peak_index * 44100/1024;
        printf("Peak freq: %.2f Hz, Magnitude: %.2f\n", frequency, peak_value);
    }

    cleanup_audio();
    return 0;
}