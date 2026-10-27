# LLL Reduction in C

A (naïve) C implementation of the Lenstra–Lenstra–Lovász (LLL) lattice basis reduction algorithm.
This project implements LLL reduction using Gram–Schmidt orthogonalisation and the Lovász condition.

## Project Structure
    .
    ├── include/    # Header files (.h)
    ├── src/        # Source files (.c)
    ├── Makefile    # Build configuration
    ├── matrix.txt  # Input matrix
    └── README.md

## Compilation

Compile the project using `make`:

    make

The executable `main` takes exactly one argument, a txt file containing a matrix :

    ./main matrix.txt

Where `matrix.txt` is structured in the following way:

    1|3        # Number of columns of the matrix
    2|3        # Number of lines of the matrix
    3|1 -1 3    # The matrix itself with a space between every entry. The entries must be integers.
    4|1 0 5
    5|1 2 6

To remove the generated executable and object files:

    make clean

## What I am working on

- [ ] Writing the output to a file.
- [x] Making a function that checks whether a result is correct.
- [ ] Implementing BKZ.
- [ ] Optimize both LLL and BKZ and run tests on multiple examples to compare efficiency.
