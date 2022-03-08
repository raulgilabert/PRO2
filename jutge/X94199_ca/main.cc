#include <vector>
#include "Estudiant.hh"

using namespace std;

void simplificar_vector(vector<Estudiant>& v, int& pos) {
    /* Pre: v=V, v.size () > 0 i les notes d'un mateix estudiant son 
     * consecutives
     *
     * Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de
     * V nomes hi apareix un cop a v [0.. pos], amb la nota mes alta i en el
     * mateix ordre que a V
     */

    pos = 0;
    
    int size = v.size(), dni = v[0].consultar_DNI();
    double mark;

    //if (v[0].te_nota())
	mark = v[0].consultar_nota();
    
    for (int i = 1; i < size; ++i) {
	int curr_dni = v[i].consultar_DNI();

	if (dni == curr_dni) {
	    if (v[i].te_nota()) {
		double curr_mark = v[i].consultar_nota();
		if (not v[pos].te_nota()) {
		    v[pos].afegir_nota(curr_mark);

		    mark = curr_mark;
		}

		else if (curr_mark > mark) {
		    v[pos].modificar_nota(curr_mark);
			
		    mark = curr_mark;
		}
	    }
	}

	else {
	    v[++pos] = v[i];
	    
	    dni = v[pos].consultar_DNI();

	    if (v[pos].te_nota())
		mark = v[pos].consultar_nota();
	}
    }
}
