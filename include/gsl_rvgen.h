/*  GSL-INT -- Some useful interfaces for GSL-INT
    Copyright (C) 2014 David Barajas-Solano

    This program is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    This project is based on code from the Dieharder project Copyright
    (C) 2003 by Robert G. Brown <rgb@phy.duke.edu>
    License: <http://www.gnu.org/licenses/> GPL version 2 or higher
*/

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
