
typedef struct filter {
  double a[20];
  double b[20];

  double X[20];
  double Y[20];

  int    NP;

  double a0;
  double a1;
  double a2;
  double b0;
  double b1;
  double b2;
} ChebFilter;

ChebFilter* call_205(int P, ChebFilter* filter, double FC, int NP, int LH, double PR);

ChebFilter* create_che_filter(int NP, double PR, int LH, double FC);
ChebFilter* create_bw_low_pass_filter(int NP, double FC);

ChebFilter* create_bw_high_pass_filter(int NP, double FC);
ChebFilter* create_che_low_pass_filter(int NP, double FC, double PR);
ChebFilter* create_che_high_pass_filter(int NP, double FC, double PR);

double applyfilter(ChebFilter* filter, double X0);