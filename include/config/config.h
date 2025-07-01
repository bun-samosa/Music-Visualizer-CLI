#ifndef CONFIG_H
#define CONFIG_H

typedef struct config{
    int bar_count;        // Number of bars across terminal
    int max_height;       // Max height of each bar
    int refresh_rate;     // FPS
    float smoothing;      // Bar smoothing factor [0.0, 1.0]
} Config;

/**
 @brief Returns a Config struct populated with default values. These values control the behavior and appearance of the visualizer.
*/
Config default_config();

#endif