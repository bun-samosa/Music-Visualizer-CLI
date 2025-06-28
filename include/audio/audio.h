#ifndef AUDIO_H
#define AUDIO_H

#include <stdint.h>
#include <stddef.h>

/*
To initialize PulseAudio
*/
int init_audio();


/**
  @brief Read raw audio samples from the system's audio monitor source.
 
  Fetches a specified number of 16-bit PCM audio samples 
  from the PulseAudio monitor source that was initialized via `init_audio()`. 
  The samples are stored in the buffer provided by the caller.
 
  The function assumes the stream is already initialized and open, and reads
  audio in mono format at a fixed sample rate (like 44100 Hz [GPT said : More conventional and accurate]).
 
  @param buffer A pointer to an int16_t buffer that will store the audio samples.
                [buffer must be large enough to store count samples]
  
  @param count  The number of 16-bit samples to read.
 
  @return int   0 : success, -1 : failure
 */
int get_audio_samples(int16_t *buffer, size_t count);


/*
Free PulseAudio resources
*/
void cleanup_audio();

#endif