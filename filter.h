
typedef struct filter {
  double a0;
  double a1;
  double a2;
  double b0;
  double b1;
  double b2;

//  double X0;
  double X1;
  double X2;
  double Y1;
  double Y2;
} ChebFilter;

ChebFilter* call_205(int P, ChebFilter* filter, double FC, int NP, int LH, double PR);

ChebFilter* create_che_filter(int NP, double PR, int LH, double FC);
ChebFilter* create_bw_low_pass_filter(int NP, double FC);

ChebFilter* create_bw_high_pass_filter(int NP, double FC);
ChebFilter* create_che_low_pass_filter(int NP, double FC, double PR);
ChebFilter* create_che_high_pass_filter(int NP, double FC, double PR);

double applyfilter(ChebFilter* filter, double X0);