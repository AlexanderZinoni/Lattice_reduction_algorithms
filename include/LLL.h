#ifndef LLL_H
#define LLL_H

#include "utils.h"
#include <stdbool.h>

double *dot_prod_matrix(int *b, double *b_star, size_t n, size_t k);


void LLL_reduction(int *basis, size_t n, size_t k, double delta);


bool verify_result(int *mat, size_t n, size_t k, double delta);


#endif