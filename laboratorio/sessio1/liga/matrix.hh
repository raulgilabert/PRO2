#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>

using namespace std;

struct match {
    int local, visitant;
};

typedef vector<vector<match> > Matrix;

struct team {
    int id, points, scored_goals, received_goals;
};

typedef vector<team> teams;


void read_matrix(Matrix& m);
// Pre: text input of integers N and M and N*M*2 integers
// Post: matrix N*M of pairs woth the integers received

void print(const teams& m);
// Pre: matrix of integers of 4 columns of size
// Post: the matrix printed

#endif
