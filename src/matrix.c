#include "matrix.h"

int *read_matrix(const char *filename, size_t *n, size_t *k){
	FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(0);
    }

    //Read columns from the first line
    if (fscanf(file, "%zu", k) != 1) {
        fprintf(stderr, "Error: Could not read number of columns.\n");
        fclose(file);
        exit(0);
    }

    // Read n from the second line
    if (fscanf(file, "%zu", n) != 1) {
        fprintf(stderr, "Error: Could not read number of lines.\n");
        fclose(file);
        exit(0);
    }

    size_t rows = *n;
    size_t cols = *k;

    // create empty mat
    int *mat = new_mat(rows, cols);
    if (mat == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for matrix.\n");
        fclose(file);
        exit(0);
    }

    // 4. Read the matrix elements sequentially
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < rows; j++) {
            if (fscanf(file, "%d", &mat[i * cols + j]) != 1) {
                fprintf(stderr, "Error: Unexpected end of file or invalid matrix data.\n");
                free(mat);
                fclose(file);
                exit(0);
            }
        }
    }

    fclose(file);
    return mat;
}


