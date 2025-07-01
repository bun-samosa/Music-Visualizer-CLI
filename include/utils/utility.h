#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

/*
 Helper functions for rendering,math,terminal control.
*/


/**
 @brief Clamp a value between a minimum and maximum.
 
 @param value Value to clamp.
 @param min   Minimum limit.
 @param max   Maximum limit.
 @return int  Clamped result.
*/
int clamp(int value, int min, int max);


/**
 @brief Linearly map a value from one range to another.
 
 @param value   Input value to map.
 @param in_min  Lower bound of the input range.
 @param in_max  Upper bound of the input range.
 @param out_min Lower bound of the output range.
 @param out_max Upper bound of the output range.
 @return float  Mapped result.
 */
float map_range(float value, float in_min, float in_max, float out_min, float out_max);


/**
 @brief Get current terminal size (width and height in characters).
 
 @param width  Pointer to store terminal width (columns).
 @param height Pointer to store terminal height (rows).
*/
void get_terminal_size(int *width, int *height);


/**
 @brief Allocate memory and exit with error if allocation fails.
 
 @param size Number of bytes to allocate.
 @return void* Pointer to allocated memory.
*/
void* xmalloc(size_t size);

#endif