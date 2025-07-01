#include "../../include/fft/fft.h"
#include <fftw3.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

static fftwf_plan fft_plan = NULL;
static float *window = NULL;
static float *in_buffer = NULL;
static fftwf_complex *out_buffer = NULL;
static size_t fft_size = 0;

int init_fft(size_t size) {
    fft_size = size;
    window = (float *)malloc(sizeof(float)*size);
    in_buffer = (float *)fftwf_malloc(sizeof(float)*size);
    out_buffer = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex)*(size/2 + 1));

    if (!window || !in_buffer || !out_buffer) {
        return -1;
    }

    for (size_t i = 0; i < size; i++) {
        window[i] = 0.5f * (1.0f - cosf((2.0f*PI*i)/(size-1)));
    }

    fft_plan = fftwf_plan_dft_r2c_1d((int)size, in_buffer, out_buffer, FFTW_MEASURE);
    if (!fft_plan) {
        return -1;
    }
    return 0;
}

void compute_fft(float *in, float *out, size_t size) {
    if (!fft_plan || size!=fft_size) {
        return;
    }

    for (size_t i=0;i<size; i++){
        in_buffer[i] = in[i]*window[i];
    }

    fftwf_execute(fft_plan);

    for (size_t i=0; i<size/2; i++) {
        float real = out_buffer[i][0];
        float imag = out_buffer[i][1];
        out[i] = sqrtf(real*real+imag*imag);
    }
}

void cleanup_fft() {
    if (fft_plan) 
        fftwf_destroy_plan(fft_plan);

    if (window) 
        free(window);

    if (in_buffer) 
        fftwf_free(in_buffer);

    if (out_buffer) 
        fftwf_free(out_buffer);

    fft_plan = NULL;
    window = NULL;
    in_buffer = NULL;
    out_buffer = NULL;
    fft_size = 0;
}