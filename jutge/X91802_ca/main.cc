#include <iostream>
#include <vector>

#include "Estudiant.hh"

using namespace std;

pair<int, int> max_min_vest(const vector<Estudiant>& v) {    
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */


    int num = v.size();

    pair<int, int> positions;
    positions.first = positions.second = -1;

    for (int i = 0; i < num; ++i) {
	if (v[i].te_nota()) {
	    double nota = v[i].consultar_nota();

	    if (positions.first == -1)
		positions.first = positions.second = i;
	    else {
		double max = v[positions.first].consultar_nota(),
		       min = v[positions.second].consultar_nota();

		if (nota > max)
		    positions.first = i;
		
		else if (nota == max) {
		    double dni = v[i].consultar_DNI(),
			   max_dni = v[positions.first].consultar_DNI();

		    if (dni < max_dni)
			positions.first = i;
		}

		else if (nota < min)
		    positions.second = i;
		
		else if (nota == min) {
		    double dni = v[i].consultar_DNI(),
			   min_dni = v[positions.second].consultar_DNI();

		    if (dni < min_dni)
			positions.second = i;
		}
	    }
	}
    }

    return positions;
}


