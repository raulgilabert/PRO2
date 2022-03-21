#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt> &l) {
    ParInt par;
    bool ok = par.llegir();
 
    while (ok) {
        l.push_back(par);
        ok = par.llegir();
    }
}
