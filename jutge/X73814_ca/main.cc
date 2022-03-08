#include <vector>
#include <iostream>
#include "Estudiant.hh"

using namespace std;

vector<Estudiant> leer() {
// Pre: un entero n y una secuencia de n enteros y reales por el canal estándar
// Post: vector con n elementos Estudiant

    int n;
    cin >> n;

    vector<Estudiant> v(n);

    for (int i = 0; i < n; ++i) {
    	Estudiant est;
	est.llegir();

	v[i] = est;
    }

    return v;
}

vector<Estudiant> filtrar(const vector<Estudiant>& v) {
    int current_dni = v[0].consultar_DNI(), num = v.size();

    vector<Estudiant> vec;

    vec.push_back(v[0]);

    int i = 0;
    for (int j = 1; j < num; ++j) {
	current_dni = v[j].consultar_DNI();

	if (current_dni != vec[i].consultar_DNI()) {
	    vec.push_back(v[j]);
	    ++i;
	}
	else if (v[j].te_nota()) {
	    double nota = v[j].consultar_nota();

	    if (not vec[i].te_nota())
		vec[i].afegir_nota(nota);
	    else if (nota > vec[i].consultar_nota())
		vec[i].modificar_nota(nota);
	}
    }

    return vec;
}

void print(const vector<Estudiant>& v) {
    int num = v.size();

    for (int i = 0; i < num; ++i) {
	cout << v[i].consultar_DNI() << ' ';

	if (v[i].te_nota())
	    cout << v[i].consultar_nota() << endl;
	else
	    cout << "NP" << endl;
    }
}

int main() {
    print(filtrar(leer()));
}

