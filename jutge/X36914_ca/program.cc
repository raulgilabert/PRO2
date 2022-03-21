#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"

int main() {
    list<Estudiant> l;
    LlegirLlistaEstudiant(l);

    list<Estudiant>::iterator it = l.begin();
    list<Estudiant>::iterator end = l.end();

    int counter = 0, dni;
    cin >> dni;

    while (it != end) {
	if ((*it).consultar_DNI() == dni)
	    ++counter;

	++it;
    }

    cout << dni << ' ' << counter << endl;
}
