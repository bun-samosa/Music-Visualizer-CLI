#ifndef RENDER_H
#define RENDER_H

/**
 @brief Render bar graph in terminal using vertical bars (Unicode + ANSI).

 Takes an array of bar heights and prints a vertical visualization responsive to terminal dimensions.
 
 @param bars        Array of integers for bar heights.
 @param bar_count   Number of bars.
 @param max_height  Maximum height (number of rows) for visualization.
 */
void render_bars(const int *bars, int bar_count, int max_height);

#endif // RENDER_H