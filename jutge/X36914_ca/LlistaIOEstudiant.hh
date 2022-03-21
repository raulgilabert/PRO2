#ifndef LlistaIOEstudiant
#define LlistaIOEstudiant

#include <list>
#include "Estudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l);
// Pre: l és buida; el canal estandar d’entrada conté parelles de valors 
// <enter, double>, acabat per un parell 0 0
// Post: s’han afegit al final de l els estudiants llegits fins al 0 0 
// (no inclòs)

void EscriureLlistaEstudiant(list<Estudiant>& l); //(opcional)
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l

#endif
