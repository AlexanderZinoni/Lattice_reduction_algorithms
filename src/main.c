#include "utils.h"
#include "matrix.h"
#include "LLL.h"

int main(int argc, char **argv){

	if (argc==1 || argc>2){
		printf("Requires exatcly one argument: matrix filename.\n");
		return 0;
	}

	char *filename = argv[1];

	size_t n;
	size_t k;

	int *mat = read_matrix(filename, &n, &k);

	printf("Input Matrix: \n");
	print_mat(mat,n,k);

	LLL_reduction(mat, n, k, 0.75);

	printf("\nLLL reduced matrix:\n");
	print_mat(mat,n,k);

	if (verify_result(mat, n, k, 0.75)){
		printf("\nReduction Successful!\n");
	}

	free(mat);
	return 1;
}