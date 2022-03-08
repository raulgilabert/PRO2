#include "Estudiant.hh"
#include <string>
#include <vector>


using namespace std;


vector<Estudiant> leer() {
    // Create vector of assigs to read
    int num, asigs, sel_asigs;

    cin >> num >> asigs >> sel_asigs;

    vector<int> asigs_to_check(sel_asigs);

    for (int i = 0; i < sel_asigs; ++i)
	cin >> asigs_to_check[i];

    // Create vector of students

    vector<Estudiant> students(num);

    for (int i = 0; i < num; ++i) {
	int dni;
	cin >> dni;
	Estudiant est(dni);

	int k = 0;
	double note;

	double sum = 0;

	for (int j = 0; j < sel_asigs; ++j) {
	    for (; k < asigs_to_check[j]; ++k) {
		cin >> note;
	    }

	    sum += note;
	}

	string s;
	getline(cin, s);

	sum /= double(sel_asigs);

	

	est.afegir_nota(sum);

	students[i] = est;
    }

    return students;
}


void print(const vector<Estudiant>& v) {
    int size = v.size();

    for (int i = 0; i < size; ++i) {
	v[i].escriure();
    }
}

int main() {
    print(leer());
}
