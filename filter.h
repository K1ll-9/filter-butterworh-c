
typedef struct filter {
  double a[20]; // inputs coefficients
  double b[20]; // output coefficients

  double X[20]; // history of inputs
  double Y[20]; // history of outputs

  int    NP;    // Nomber of Poles - Order

  double a0;    // internal
  double a1;
  double a2;
  double b0;
  double b1;
  double b2;
} ChebFilter;


typedef struct doublefilter {
  int         type;
  ChebFilter  *lp_filter;
  ChebFilter  *hp_filter;
} dChebFilter;

ChebFilter* call_205(int P, ChebFilter* filter, double FC, int NP, int LH, double PR);

ChebFilter* create_che_filter(int NP, double PR, int LH, double FC);
ChebFilter* create_che_low_pass_filter(int NP, double FC, double PR);
ChebFilter* create_che_high_pass_filter(int NP, double FC, double PR);


dChebFilter* create_bw_low_pass_filter(int NP, double FC);
dChebFilter* create_bw_high_pass_filter(int NP, double FC);
dChebFilter* create_bw_bp_pass_filter(int NP, double FC, double winwidth);

double applyfilter(ChebFilter* filter, double X0);