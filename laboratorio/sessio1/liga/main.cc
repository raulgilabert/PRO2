#include <iostream>
#include <vector>
#include <algorithm>

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

// Formato de impresión de datos:
//
// Identificador | Puntos | Goles a favor | Goles en contra

teams create_matrix(const Matrix& goals) {
    int rows = goals.size();

    teams data(rows);

    for (int i = 1; i <= rows; ++i)
	data[i - 1].id = i;

    return data;
}


bool cmp(team& a, team& b) {
    if (a.points != b.points)
	return (a.points > b.points);
    else { 
	int a_diff = a.scored_goals - a.received_goals, 
	    b_diff = b.scored_goals - b.received_goals;

	if (a_diff != b_diff)
	    return (a_diff > b_diff);
	else
	    return (a.id < b.id);	    
    }
}


void calc_points(const Matrix& goals, teams& points) {
    int rows = goals.size(), columns = goals[0].size();

    for (int i = 0; i < rows; ++i) {
	for (int j = 0; j < columns; ++j) {
	    if (j != i) {
		if (goals[i][j].local > goals[i][j].visitant) {
		    // The local team wins

		    points[i].points += 3;
		}
		else if (goals[i][j].local < goals[i][j].visitant) {
		    // The visitant team wins

		    points[j].points += 3;
		}
		else {
		    // Tie
		    
		    ++points[i].points;
		    ++points[j].points;
		}

		// Goals
		points[i].scored_goals += goals[i][j].local;
		points[i].received_goals += goals[i][j].visitant;
		points[j].scored_goals += goals[i][j].visitant;
		points[j].received_goals += goals[i][j].local;
	    }
	}
    }

    // Sort the points vector
    sort(points.begin(), points.end(), cmp);
}


int main() {
    Matrix data;
    read_matrix(data);

    teams points = create_matrix(data);
    calc_points(data, points);
    print(points);
}
