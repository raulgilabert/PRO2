#include <iostream>
#include <vector>

#include "matrizIOint.hh"

using namespace std;

typedef vector<vector<int> > Matrix;


Matrix product(const Matrix& m1, const Matrix& m2) {
    int rowsm1 = m1.size(), columnsm1 = m1[0].size(), columnsm2 = m2[0].size();

    Matrix prod(rowsm1, vector<int>(columnsm2, 0));

    for (int i = 0; i < rowsm1; ++i) {
	for (int j = 0; j < columnsm2; ++j) {
	    // Acceso a cada espacio de la matriz resultado
	    
	    for (int k = 0; k < columnsm1; ++k) {
		prod[i][j] += m1[i][k] * m2[k][j];
	    }
	}
    }

    return prod;
}


int main() {
    cout << "First matrix" << endl;
    Matrix m1;
    leer_matriz_int(m1);  
    cout << "Second matrix" << endl;
    Matrix m2;
    leer_matriz_int(m2);

    Matrix s = product(m1, m2);

    cout << "The product is: " << endl;
    escribir_matriz_int(s);
}
