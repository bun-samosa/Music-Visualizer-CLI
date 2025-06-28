gcc tests/fft.c \
    src/audio/audio.c src/fft/fft.c \
    -o audio_fft_test \
    -Iinclude -lpulse-simple -lpulse -lfftw3f -lm

./tests/fft.c