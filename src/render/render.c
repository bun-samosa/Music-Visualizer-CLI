#include "../../include/render/render.h"
#include "../../include/color/color.h"
#include "../../include/utils/utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BAR_CHAR "█"
#define CLEAR_SCREEN "\033[2J"
#define MOVE_CURSOR_HOME "\033[H"
#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

void render_bars(const int *bars, int bar_count, int max_height) {
    int term_width, term_height;
    get_terminal_size(&term_width, &term_height);

    if (max_height > term_height) 
        max_height = term_height - 2;

    const char *empty = (term_width >= bar_count * 2) ? "  ":" ";

    printf(HIDE_CURSOR);
    printf(MOVE_CURSOR_HOME);

    for (int row = max_height; row > 0; row--) {
        for (int i = 0; i < bar_count; i++) {
            if (bars[i] >= row) {
                printf("%s%s", get_bar_color(bars[i]), BAR_CHAR);
            } else {
                printf("%s", empty); // refer line 24
            }
        }
        printf("\033[0m\n");
    }

    for (int i = 0; i < bar_count; i++) {
        printf("\u2501\u2501");
    }
    printf("\n");

    fflush(stdout);
    usleep(16000); // around 60 FPS
}