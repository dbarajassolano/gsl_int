#include <stdio.h>
#include "gsl_rvgen.h"
#include "mymct.h"

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/* Global variables */
static gsl_rng *rn_gen = NULL;

int gsl_rv_init(void)
{
	const gsl_rng_type *rn_type;
	gsl_rng_env_setup();
	rn_type = gsl_rng_default;
	rn_gen = gsl_rng_alloc(rn_type);
	if (PTRCHECK("Memory error", &rn_gen, NULL))
		return 1;
	return 0;
}

void gsl_rv_free(void)
{
	gsl_rng_free(rn_gen);
}

void gsl_rv_set(unsigned long int seed)
{
	gsl_rng_set(rn_gen, seed);
}

/* Function for generating a vector of normally distributed random
   numbers */
int gsl_rvgen_normal(unsigned int M, double *rv, void *_context){
	
	int i;
	double *rv_ptr = rv;
	struct gsl_rv_context *context = _context;
	
	if (rn_gen == NULL)
		return 1;
	
	for (i = 0; i < M; i++, rv_ptr++)
		*rv_ptr = context->mean + gsl_ran_gaussian(rn_gen, context->sigma);
	return 0;  
}

/* Function for obtaining a random number from /dev/urandom for
   seeding a pseudo-random number generator.
   Adapted from code from the Dieharder project
   http://www.phy.duke.edu/~rgb/General/dieharder.php */
unsigned long int random_seed(int verbose_flag){
	
	unsigned int seed;
	FILE *devrandom;
	
	if ((devrandom = fopen("/dev/urandom", "r")) == NULL) {
		fprintf(stderr, "Cannot open /dev/urandom, setting seed to 0.\n");
		seed = 0;
	} else {
		if (fread(&seed, sizeof(seed), 1, devrandom) == 1){
			if (verbose_flag) printf("Got seed %u from /dev/urandom.\n",seed);
			fclose(devrandom);
		} else {
			fprintf(stderr, "Cannot read seed from /dev/urandom, setting seed to 0.\n");
			seed = 0;
		}
	}
	return seed;
}
