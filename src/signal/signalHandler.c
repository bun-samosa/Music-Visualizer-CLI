#define _POSIX_C_SOURCE 200809L // "for incomplete type "struct sigaction" is not allowedC/C++"

#include "../../include/signal/signalHandler.h"
#include "../../include/audio/audio.h"
#include "../../include/fft/fft.h"
#include "../../include/render/render.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define SHOW_CURSOR "\033[?25h"

void handle_signal(int signum) {
    (void)signum;

    printf(SHOW_CURSOR);

    cleanup_audio();
    cleanup_fft();

    printf("\033[2J\033[H");
    fflush(stdout);

    exit(0);
}

void setup_signal_handlers() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
}