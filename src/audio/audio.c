#include "../../include/audio/audio.h"
#include <pulse/simple.h>
#include <pulse/error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static pa_simple *pa_stream = NULL;

#define SOURCE_FILE "./.monitorrc" // env workaround
#define MAX_SOURCE_LEN 256

int init_audio() {
    char monitor_source[MAX_SOURCE_LEN] = {0};

    FILE *fp = fopen(SOURCE_FILE, "r");
    if (fgets(monitor_source, MAX_SOURCE_LEN, fp) == NULL) {
            fclose(fp);
            return -1;
        }
        monitor_source[strcspn(monitor_source, "\n")] = 0;
        fclose(fp);

    pa_sample_spec ss = {
        .format = PA_SAMPLE_S16LE, // 16-bit PCM
        .rate = 44100,             // 44.1kHz
        .channels = 1              // mono
    };

    int error;
    pa_stream = pa_simple_new(
        NULL,               // default server
        "Visualizer",       // app name
        PA_STREAM_RECORD,
        monitor_source,     // source from file
        "audio",            // stream name
        &ss,
        NULL, NULL,
        &error
    );

    return 0;
}

int get_audio_samples(int16_t *buffer, size_t count) {

    int error;
    size_t bytes = count * sizeof(int16_t);

    if (pa_simple_read(pa_stream, buffer, bytes, &error) < 0) {
        fprintf(stderr, "Check src/audio/audio.c: %s\n", pa_strerror(error));
        return -1;
    }

    return 0;
}

void cleanup_audio() {
    if (pa_stream) {
        pa_simple_free(pa_stream);
        pa_stream = NULL;
    }
}