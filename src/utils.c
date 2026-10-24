#include "utils.h"


int *new_mat(size_t n, size_t k){
	int *mat = malloc(n * k * sizeof(int));

	if (mat == NULL){
		return NULL;
	}

	for (size_t i = 0; i<n; i++){
		for (size_t j = 0; j<k; j++){
			mat[i*k+j] = 0;
		}
	}

	return mat;
}


double *new_double_mat(size_t n, size_t k){
	double *mat = malloc(n * k * sizeof(double));

	if (mat == NULL){
		return NULL;
	}

	for (size_t i = 0; i<n; i++){
		for (size_t j = 0; j<k; j++){
			mat[i*k+j] = 0;
		}
	}

	return mat;
}


int *new_vec(size_t n){
	return new_mat(n,1);
}


double *new_double_vec(size_t n){
	return new_double_mat(n,1);
}


void print_vec(const int *vec, size_t n){
	printf("[");
	for (size_t i = 0; i<n; i++){
		printf("%i,", vec[i]);
	}
	printf("\b]\n");
}


void print_vec_double(const double *vec, size_t n){
	printf("[");
	for (size_t i = 0; i<n; i++){
		printf("%f,", vec[i]);
	}
	printf("\b]\n");
}


void vec_sum(int *v, const int *u, size_t n){
	for (size_t i = 0; i<n; i++){
		v[i] += u[i];
	}
}


void vec_scalar(int *v, int s, size_t n){
	for (size_t i = 0; i<n; i++){
		v[i] *= s;
	}
}


void print_mat(const int *mat, size_t n, size_t k){
	printf("[");

	for (size_t i = 0; i<n; i++){
		printf("[");
		for (size_t j = 0; j<k; j++){
			printf("%i,", mat[i*k+j]);
		}
		printf("\b]");
		if ((i+1)!=n)
			printf("\n");
	}
	printf("]\n");
}


void print_mat_double(const double *mat, size_t n, size_t k){
	printf("[");

	for (size_t i = 0; i<n; i++){
		printf("[");
		for (size_t j = 0; j<k; j++){
			printf("%f,", mat[i*k+j]);
		}
		printf("\b]");
		if ((i+1)!=n)
			printf("\n");
	}
	printf("]\n");
}


double dot_prod(const int *u, const double *v, size_t n){
	double res = 0;

	for (size_t i = 0; i<n;i++){
		res += ((double) u[i]) * v[i];
	}

	return res;
}


double dot_prod_double(const double *u, const double *v, size_t n){
	double res = 0;

	for (size_t i = 0; i<n;i++){
		res += u[i] * v[i];
	}

	return res;
}


double col_norm_double(size_t n, size_t k, double *mat, int i){
	double norm = 0;

	for (size_t j = 0; j<n; j++){
		norm += mat[j*k+i] * mat[j*k+i];
	}

	return norm;
}


int *vec_from_col(const int *mat, size_t n, size_t k, int j){
	int *res = new_vec(n);

	for(size_t i = 0; i<n;i++){
		res[i] = mat[i*k+j];
	}

	return res;
}


double *vec_from_col_double(const double *mat, size_t n, size_t k, int j){
	double *res = new_double_vec(n);

	for(size_t i = 0; i<n;i++){
		res[i] = mat[i*k+j];
	}

	return res;
}


double *gram_schmidt(size_t n, size_t k, const int *V){

	double *U = new_double_mat(n,k);

	for (size_t i=0; i<n; i++){
		U[i*k] = V[i*k];
	}
	for (size_t i=1; i<k; i++){

		// i-th column of U becomes the i-th column of j
		for (size_t j=0; j<n; j++){
			U[j*k+i] = V[j*k+i];
		}
		for (size_t j=0; j<i; j++){
			
			//prod is the inner prod of the i-th column and the j-th column of U 
			double prod = 0;
			for (size_t x=0; x<n; x++){
				prod += U[x*k+i]*U[x*k+j];
			}
			prod /= col_norm_double(n,k,U,j);

			for (size_t x=0; x<n; x++){
				U[x*k+i] = U[x*k+i] -  prod * U[x*k+j];
			}
		}
	}

	return U;
}
