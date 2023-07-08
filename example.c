#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "filter.h"

#define DEBUG  0
#define DATA_LEN  2205
#define RUNS      3
#define ORDER     4

int main() {

  ChebFilter* filter = create_bw_low_pass_filter(ORDER, (double)2*M_PI*205/44100);
  double      input[DATA_LEN];
  double      filtered_signal[RUNS][DATA_LEN];

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

  for(int j=0; j<RUNS; j++) {
    printf("Run #%d:\n", j);
    for(int i=0; i<DATA_LEN; i++) {
      filtered_signal[j][i] = applyfilter(filter, input[i]);
    }
  }

  printf("Comparing results:\n");
  for(int i=0; i<500; i++) {
    printf("[bp_filter %i] input: %lf | ", i, input[i]);
    for(int j=0; j<RUNS; j++)
      printf(" f_out#%d %lf |", j, filtered_signal[j][i]);
    printf("\n");
  }

  free(filter);

  return(0);
}
