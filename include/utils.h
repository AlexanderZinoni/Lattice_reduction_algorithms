#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Creates a matrix (n rows, k cols) of all zeroes. Remember to free after use.
int *new_mat(size_t n, size_t k);


// Same but entries are doubles.
double *new_double_mat(size_t n, size_t k);


// Creates a vector of size n of all zeroes. Remember to free after use.
int *new_vec(size_t n);


double *new_double_vec(size_t n);


// Prints a vector of size n.
void print_vec(const int *v, size_t n);
void print_vec_double(const double *vec, size_t n);

// v <- u + v. u and v of size n.
void vec_sum(int *v, const int *u, size_t n);

// v <- s*v. v of size n.
void vec_scalar(int *v, int s, size_t n);


// Prints a matrix (n rows, k cols).
void print_mat(const int *m, size_t n, size_t k);


// Same but with doubles.
void print_mat_double(const double *mat, size_t n, size_t k);


// Returns the dot product of two vectors of size n.
double dot_prod(const int *u, const double *v, size_t n);


double dot_prod_double(const double *u, const double *v, size_t n);


// returns the norm of the 
double col_norm_double(size_t n, size_t k, double *V, int col);


double *vec_from_col_double(const double *mat, size_t n, size_t k, int j);

int *vec_from_col(const int *mat, size_t n, size_t k, int j);

// Non-normalised Gram-Schmidt
double *gram_schmidt(size_t n, size_t k, const int *V);

#endif