#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>

struct pair {
    int local, visitant;
};

typedef vector<vector<pair> > Matrix;

void read_matrix(Matrix& m);
// Pre: text input of integers N and M and N*M*2 integers
// Post: matrix N*M of pairs woth the integers received

void print_matrix(const Matrix& m);
// Pre: matrix of integers of 4 columns of size
// Post: the matrix printed

#endif
