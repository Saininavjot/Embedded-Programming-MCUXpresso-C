/*
 * embt_print_vector.h
 *
 *  Created on: Oct. 22, 2019
 *      Author: user
 */

#ifndef EMBT_PRINT_VECTOR_H_
#define EMBT_PRINT_VECTOR_H_
#include <stdio.h>
	#include <stdlib.h>
#include <gsl/gsl_vector_double.h>
	#include <gsl/gsl_matrix_double.h>
	#include <gsl/gsl_rng.h>
	#include <gsl/gsl_randist.h>

gsl_matrix *embt_print_vector(const gsl_vector *u);

#endif /* EMBT_PRINT_VECTOR_H_ */
