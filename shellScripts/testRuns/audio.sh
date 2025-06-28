gcc tests/audio.c src/audio/audio.c -Iinclude -lpulse -lpulse-simple -o tests/audio_test
./tests/audio_test