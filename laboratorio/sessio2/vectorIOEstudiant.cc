#include "vectorIOEstudiant.hh"

vector<Estudiant> leer_vector() {
    cout << "Escribe el número de estudiantes" << endl;
    int num;
    cin >> num;

    vector<Estudiant> vec(num);

    for (int i = 0; i < num; ++i) {
	cout << "Escribe un estudiante <DNI nota>" << endl;
	vec[i].llegir();
    }

    return vec;
}


void redondear_vector(vector<Estudiant>& vec) {
    int num = vec.size();

    for (int i = 0; i < num; ++i) {
	if (vec[i].te_nota())
	    vec[i].modificar_nota(((int) (10.0 * (vec[i].consultar_nota() + 
			    0.05))) / 10.0);
    }
}


void escribir_vector(vector<Estudiant>& vec) {
    int num = vec.size();

    for (int i = 0; i < num; ++i) {
	cout << "El estudiante con la nota redondeada o NP" << endl;
	vec[i].escriure();
    }
}

