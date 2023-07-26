#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "filter.h"

#define DEBUG  0
#define DATA_LEN  1006507 // # frames
#define RUNS      1
#define ORDER     2


#include "tinywav.h"

#define NUM_CHANNELS 1
#define SAMPLE_RATE 48000
#define BLOCK_SIZE 480

//#define FC        205
#define FC        102.5


int main() {

/*
  NP : Number of poles / Order
  PR: Percent ripple
  LH: 0 for lowpass, 1 for highpass
  FC: cutoff frequency (0 to 0.5), typically fc(Hz)/SR(Hz), with fc<SR/2. Example: (double)1000/44100
*/
  //ChebFilter* filter = create_bw_low_pass_filter(ORDER, (double)FC/SAMPLE_RATE);
  ChebFilter* filter = create_che_filter(4, 0.5, 0, FC/48000.0);
  double      input[DATA_LEN];
  double      *output;

  output=(double*)malloc(DATA_LEN*sizeof(double));

  TinyWav tw;
  tinywav_open_read(&tw, "data/guitar_E.wav", TW_SPLIT );


  int line=0;
  for (int i = 0; i < 2096; i++) {
    float samples[NUM_CHANNELS * BLOCK_SIZE];

    float* samplePtrs[NUM_CHANNELS];

    for (int j = 0; j < NUM_CHANNELS; ++j) {
      samplePtrs[j] = samples + j*BLOCK_SIZE;
    }

    tinywav_read_f(&tw, samplePtrs, BLOCK_SIZE);

    for(int k=0; k<BLOCK_SIZE; k++)
      input[line++]=(double)samplePtrs[0][k];
  }

  tinywav_close_read(&tw);

  printf("Data stored into input[].\n");

  for(int i=0; i<line; i++) 
    output[i] = applyfilter(filter, input[i]);

/*
  tinywav_open_write(&tw, NUM_CHANNELS, SAMPLE_RATE,
    TW_FLOAT32, // the output samples will be 32-bit floats. TW_INT16 is also supported
    TW_INLINE,  // the samples to be written will be assumed to be inlined in a single buffer.
                // Other options include TW_INTERLEAVED and TW_SPLIT
    "data/guitar_E_filtered.wav" // the output path
  );

  int c=0;
  for (int i = 0; i < 2096; i++) {
    float samples[480 * NUM_CHANNELS];
    for(int i=0; i<480; i++)
      samples[i]=(float)output[c++];
    tinywav_write_f(&tw, samples, sizeof(samples));
  }

  tinywav_close_write(&tw);
  */
 for(int i=0; i<line; i++)
   printf("%.10lf\n", output[i]);


/*
  printf("Comparing results:\n");
  for(int i=0; i<500; i++) {
    printf("[bp_filter %i] input: %lf | ", i, input[i]);
    printf(" f_out#1 %lf |", output[i]);
    printf(" a= [");
    for(int j=0; j<3; j++)
      printf(" %.6lf ", filter->a[j]);
    printf("] | b= [");
    for(int j=0; j<3; j++)
      printf(" %.6lf ", filter->b[j]);
    printf("]");
    printf("\n");
  }
  */

  free(filter);

  return(0);
}
