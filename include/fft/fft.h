#ifndef FFT_H
#define FFT_H

#include <stdlib.h>

/**
 @brief Initialize FFTW plan and necessary buffers.
  
 Must be called before compute_fft(). Sets up an FFTW plan for a given size.
  
 @param size FFT size (must be power of 2)
 @return 0 : success, -1 : failure
 */
int init_fft(size_t size);

/**
  @brief Compute the magnitude spectrum of audio samples using FFT [Fast Fourier TRansform].
 
  Takes a buffer of time-domain audio samples (from PCM stream), applies a windowing function (e.g., Hann), performs a real-to-complex Fast Fourier Transform using FFTW, and calculates the magnitude of each frequency bin.
 
  The input samples should be floating-point values, and the output
  array -> frequency-domain magnitude values.
 
  @param in     Pointer to an input array of float samples (time-domain, real values).
  @param out    Pointer to an output array of float magnitudes (frequency-domain).
  @param size   Number of samples and FFT size (must be power of 2 for efficiency [GPT said]).
 */

void compute_fft(float *in, float *out, size_t size);

void cleanup_fft();

#endif