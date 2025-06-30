#ifndef COLOR_H
#define COLOR_H

/**
 @brief Get ANSI color code for a bar based on its value.

 Currently returns bright white for all values.
 Creating this header to enable dynamic color gradients extension in future.

 @param value Bar height or amplitude.
 @return const char* ANSI color escape code string.
 */
const char* get_bar_color(int value);

#endif // COLOR_H
