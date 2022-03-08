#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b) {
    int dni = est.consultar_DNI();
    int pos = cerca_dicot(vest, 0, nest - 1, dni);

    b = (dni == vest[pos].consultar_DNI());

    if (not b) {
	vest[nest] = est;
	++nest;

	if (est.te_nota()) {
	    suma_notes += est.consultar_nota();
	    ++nest_amb_nota;
	}
    }

    ordenar_cjt_estudiants();
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool &b) {
    int pos = cerca_dicot(vest, 0, nest - 1, dni);

    b = (dni == vest[pos].consultar_DNI());

    if (b) {
        if (vest[pos].te_nota()) {
	   suma_notes -= vest[pos].consultar_nota();
	    --nest_amb_nota;
	}

	vest[pos] = vest[nest - 1];
	--nest;

	ordenar_cjt_estudiants();
    }
}
