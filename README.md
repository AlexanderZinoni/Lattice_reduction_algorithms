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

    3
    3
    1 -1 3
    1 0 5
    1 2 6

The first line is the number of columns of the matrix.
The second is the number of lines of the matrix.
Finally put the matrix itself with a space between every entry. The entries must be integers.
The parameter δ of the reduction is set to `0.75` by default.

To remove the generated executable and object files:

    make clean

## Output Example

Suppose matrix.txt is the same as in the compilation paragraph. Then `./main matrix.txt` outputs:


    Input Matrix: 
    [[1,-1,3]
    [1,0,5]
    [1,2,6]]
    
    LLL reduced matrix:
    [[0,1,-1]
    [1,0,0]
    [0,1,2]]

    Reduction Successful!


In the case where the reduction is unsuccessful, the program specifies whether the basis is not size-reduced or the Lovasz condition does not hold.


## What I am working on

- [ ] Writing the output to a file.
- [x] Making a function that checks whether a result is correct.
- [ ] Implementing BKZ.
- [ ] Optimize both LLL and BKZ and run tests on multiple examples to compare efficiency.
