#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant> &l) {
    Estudiant est;
    est.llegir();

    while (est.consultar_DNI() != 0) {
	l.push_back(est);
	est.llegir();
    }
}
