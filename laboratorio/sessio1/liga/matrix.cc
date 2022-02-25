#include "matrix.hh"

using namespace std;

void read_matrix(Matrix& m) {
    int rows;

    cin >> rows;

    m = Matrix(rows, vector<match>(rows));

    for (int i = 0; i < rows; ++i) {
	for (int j = 0; j < rows; ++j) {
	    cin >> m[i][j].local >> m[i][j].visitant;
	}
    }
}

void print(const teams& m) {
    int rows = m.size();

    for (int i = 0; i < rows; ++i) {
	cout << m[i].id << ' ' << m[i].points << ' ' << m[i].scored_goals << 
	    ' ' << m[i].received_goals << endl;
    }
}
