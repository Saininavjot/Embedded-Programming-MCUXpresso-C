/*
 * embd_mm.c
 *
 *  Created on: Oct. 22, 2019
 *      Author: user
 */
#include <stdio.h>
	#include <stdlib.h>
#include <gsl/gsl_vector_double.h>
	#include <gsl/gsl_matrix_double.h>
	#include <gsl/gsl_rng.h>
	#include <gsl/gsl_randist.h>
gsl_matrix *embt_mm(const gsl_matrix *U, const gsl_matrix *V, size_t N)
{
	gsl_matrix *W = gsl_matrix_alloc(N,N);
	double dp;
	double uk,vk;

	for (size_t i=0; i != N; ++i)
	{
		for (size_t j=0; j != N; ++j)
		{
			/* compute element (i,j) of W */
			dp = 0;
			for (size_t k=0; k != N; ++k)
			{
				uk = gsl_matrix_get(U,i,k);
				vk = gsl_matrix_get(V,k,j);
				dp += uk*vk;
			}
			gsl_matrix_set(W,i,j,dp);
		}
	}
	return W;
}

