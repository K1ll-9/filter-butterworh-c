#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "filter.h"

#define DEBUG  1
#define DATA_LEN  1006507 // # frames
#define RUNS      3
#define ORDER     4


#include "tinywav.h"

#define NUM_CHANNELS 1
#define SAMPLE_RATE 48000
#define BLOCK_SIZE 480

#define FC        205


int main() {

  //ChebFilter* filter = create_bw_low_pass_filter(ORDER, (double)2*M_PI*205/44100);
  //ChebFilter* filter = create_bw_low_pass_filter(ORDER, (double)FC/SAMPLE_RATE);
  //ChebFilter* filter = create_bw_low_pass_filter(ORDER, 0.01);
  ChebFilter* filter = create_che_filter(ORDER, 0.5, 0, 0.025);
  double      input[DATA_LEN];
  //double      filtered_signal[RUNS][DATA_LEN];

  TinyWav tw;
  tinywav_open_read(&tw, "data/guitar_E.wav", TW_SPLIT );

  //printf("# occurences: %d\n", (int)floor(DATA_LEN/BLOCK_SIZE));

  int line=0;
  //for (int i = 0; i < (int)floor((double)DATA_LEN/BLOCK_SIZE); i++) {
  for (int i = 0; i < 2096; i++) {
    float samples[NUM_CHANNELS * BLOCK_SIZE];

    float* samplePtrs[NUM_CHANNELS];

    for (int j = 0; j < NUM_CHANNELS; ++j) {
      samplePtrs[j] = samples + j*BLOCK_SIZE;
    }

    tinywav_read_f(&tw, samplePtrs, BLOCK_SIZE);

    for(int k=0; k<BLOCK_SIZE; k++) {
      //printf("#%d ", line);
      input[line++]=(double)samplePtrs[0][i];
      //printf("%0.6f\n", samplePtrs[0][k]);
    }
  }

  tinywav_close_read(&tw);

/*
  printf("Opening and reading data file...\n");
  FILE *fp = fopen("data/inputs.raw", "r");
  if(fp == NULL) {
    perror("Unable to open file!");
    return(-1);
  }
  char line[30];

  unsigned int i=0;
  while(fgets(line, sizeof(line), fp) != NULL) {
    sscanf(line, "%lf", &input[i]);
    i++;
  }
  fclose(fp);

  printf("Data stored into input[].\n");
  */

/*
  for(int j=0; j<line; j++) {
    printf("Run #%d:\n", j);
    for(int i=0; i<DATA_LEN; i++) {
      filtered_signal[j][i] = applyfilter(filter, input[i]);
    }
  }
  */

/*
  printf("Comparing results:\n");
  for(int i=0; i<500; i++) {
    printf("[bp_filter %i] input: %lf | ", i, input[i]);
    for(int j=0; j<RUNS; j++)
      printf(" f_out#%d %lf |", j, filtered_signal[j][i]);
    printf("\n");
  }
  */

  free(filter);

  return(0);
}
