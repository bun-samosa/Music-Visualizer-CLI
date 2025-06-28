#include "../../include/fft/fft.h"
#include <fftw3.h>
#include <math.h>

#define PI 3.14159265358979323846

void compute_fft(float *in, float *out, size_t size) {

    float *windowed = fftwf_alloc_real(size);
    fftwf_complex *fft_result = fftwf_alloc_complex(size / 2 + 1);

    // Apply Hann window to input
    for (size_t i = 0; i < size; i++) {
        float window = 0.5f * (1.0f - cosf((2.0f*PI*i) / (size - 1)));
        windowed[i] = in[i] * window;
    }

    fftwf_plan plan = fftwf_plan_dft_r2c_1d((int)size, windowed, fft_result, FFTW_ESTIMATE);

    fftwf_execute(plan);

    for (size_t i=0; i<size/2 + 1; i++) {
        float real = fft_result[i][0];
        float imag = fft_result[i][1];
        out[i] = sqrtf(real*real+imag*imag);
    }

    fftwf_destroy_plan(plan);
    fftwf_free(windowed);
    fftwf_free(fft_result);
}