#ifndef GSL_RVGEN_H
#define GSL_RVGEN_H

/* Structures */
struct gsl_rv_context {
	double mean;
	double sigma;
};

/* Function prototypes */
int gsl_rv_init(void);
void gsl_rv_free(void);
void gsl_rv_set(unsigned long int seed);
int gsl_rvgen_normal(unsigned int M, double *rv, void *_context);
unsigned long int random_seed();

#endif
