#ifndef BARS_H
#define BARS_H

/*
Maps FFT magnitude data to bar heights for visualization.

Divides FFT output into a fixed number of bars, computes the average magnitude for each band, and stores the result as an integer bar height. Resulting bar heights will used to render a frequency spectrum as bars in the terminal.

@param fft_data   Pointer to the array of FFT magnitudes (length: fft_size/2).
@param bars       Pointer to the output array for bar heights (length: bar_count).
@param bar_count  Number of bars (frequency bands) to map.
@param fft_size   Size of the FFT (number of input samples).
*/

void map_bars(float *fft_data, int *bars, int bar_count, int fft_size, int max_height);

#endif