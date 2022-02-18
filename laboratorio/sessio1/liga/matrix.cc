#include "matrix.hh"

void read_matrix(Matrix& m) {
    int rows;

    cin >> rows;

    m = Matrix(rows, vector<pair>(rows));

    for (int i = 0; i < rows; ++i) {
	for (int j = 0; j < rows; ++j) {
	    cin >> m[i][j].local >> m[i][j].visitant;
	}
    }
}

void print_matrix(const Matrix& m) {
    int rows = m.size(), columns = m[0].size();

    for (int i = 0; i < rows; ++i) {
	for (int j = 0; j < columns; ++j) {
	    cout << m[i][j] << ' ';
	}

	cout << endl;
    }
}
