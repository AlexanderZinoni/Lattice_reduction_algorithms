#include "LLL.h"

double *dot_prod_matrix(int *b, double *b_star, size_t n, size_t k){

	double *res = new_double_mat(k,k);

	for (size_t i = 0; i<k; i++){
		for (size_t j = 0; j<k; j++){
			int *b_i = vec_from_col(b, n, k, i);
			double *b_j = vec_from_col_double(b_star, n, k, j);

			res[i*k+j] = dot_prod(b_i, b_j, n) / dot_prod_double(b_j,b_j, n);

			free(b_i);
			free(b_j);
		}
	}

	return res;
}


void LLL_reduction(int *basis, size_t n, size_t k, double delta){
	if (delta<= 0.25 || delta >=1.0){
		printf("LLL Reduction not possible: delta must be in the interval (0.25, 1).\n");
		return;
	}

	double *b_star = gram_schmidt(n,k,basis);
	double *products = dot_prod_matrix(basis,b_star,n, k);

	size_t m=1;

	while (m<k){
		for (int j = m-1;j>=0 ;j--){

			if (fabs(products[m*k+j])> 0.5){
				for (size_t x = 0; x<n; x++){
					basis[x*k+m] = basis[x*k+m] -(round(products[m*k+j]))*basis[x*k+j];
				}

			free(b_star);
			b_star = gram_schmidt(n,k,basis);
			free(products);
			products = dot_prod_matrix(basis,b_star,n, k);
			}
		}

		double *b_m = vec_from_col_double(b_star, n, k, m);
		double *b_m1 = vec_from_col_double(b_star, n, k, m-1);

		if (dot_prod_double(b_m,b_m,n)>= (delta-products[m*k+m-1]*products[m*k+m-1])*dot_prod_double(b_m1, b_m1,n)){
			m++;
		} else {
			for (size_t x = 0; x < n; x++) {
			    int tmp = basis[x*k + m];
			    basis[x*k + m] = basis[x*k + m-1];
			    basis[x*k + m-1] = tmp;
			}
			free(b_star);
			b_star = gram_schmidt(n,k,basis);
			free(products);
			products = dot_prod_matrix(basis,b_star,n, k);
			if (m>1){
				m--;
			} else {
				m=1;
			}
		}
		free(b_m);
		free(b_m1);
	}
	free(b_star);
	free(products);
}


bool verify_result(int *basis, size_t n, size_t k, double delta){
	if (delta<= 0.25 || delta >=1.0){
		printf("LLL Reduction not possible: delta must be in the interval (0.25, 1).\n");
		return false;
	}

	bool res = true; 

	double *b_star = gram_schmidt(n,k,basis);
	double *products = dot_prod_matrix(basis,b_star,n, k);

	for (size_t i = 0; i<k; i++){
		for (size_t j = 0; j<i; j++){
			if (fabs(products[i*k + j])>0.5){
				printf("Matrix is not reduced.\n");
				res = false;
			}
		}
	}	


	for (size_t x = 0; x+1<k; x++){
		double *b_x = vec_from_col_double(b_star, n, k, x);
		double *b_x1 = vec_from_col_double(b_star, n, k, x+1);
		
		double mu_sq = products[(x+1)*k+x]*products[(x+1)*k+x];
		double b_x1_norm = dot_prod_double(b_x1,b_x1,n);
		double b_x_norm = dot_prod_double(b_x,b_x,n);

		if (delta * b_x_norm > b_x1_norm + mu_sq * b_x_norm){
			printf("Lovasz condition false.\n");
			res = false;
		}
		free(b_x);
		free(b_x1);
	}

	free(b_star);
	free(products);

	return res;
}