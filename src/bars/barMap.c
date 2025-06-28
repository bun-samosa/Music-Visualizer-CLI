// GPT Assisted (for dynamic bar heights)
#include "../../include/bars/barMap.h"
#include <stddef.h>
#include <math.h>

#define SMOOTHING_FACTOR 0.5f

// (assumes bar_count <= 256)
static float prev_bars[256] = {0};

static float max_avg = 1.0f;

void map_bars(float *fft_data, int *bars, int bar_count, int fft_size, int max_height) {
    int bins = fft_size / 2;
    int bins_per_bar = bins / bar_count;

    for (int b = 0; b < bar_count; b++) {
        float sum = 0.0f;
        int start = b * bins_per_bar;
        int end = (b == bar_count - 1) ? bins : start + bins_per_bar;
        if (end > bins) end = bins;

        for (int i = start; i < end; ++i) {
            sum += fft_data[i];
        }

        float avg = (end > start) ? sum / (end - start) : 0.0f;

        if (avg > max_avg) {
            max_avg = avg;
        } else {
            max_avg = 0.99f * max_avg + 0.01f * avg;
        }

        float scaled = log1p(avg);
        float scale_base = log1p(max_avg);

        prev_bars[b] = SMOOTHING_FACTOR * scaled + (1.0f - SMOOTHING_FACTOR) * prev_bars[b];

        int height = (int)(prev_bars[b] * max_height / scale_base);

        if (height > max_height) height = max_height;
        if (height < 0) height = 0;

        bars[b] = height;
    }
}