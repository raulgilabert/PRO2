#ifndef CuaIOParInt
#define CuaIOParInt

#include <iostream>
#include <queue>
#include "ParInt.hh"

using namespace std;

void llegirCuaParInt(queue<ParInt>& c);
// Pre: c és buida; el canal estandar d’entrada conté un nombre parell 
// d’enters, acabat pel parell 0 0
// Post: s’han encuat a c els elements llegits fins al 0 0 (no inclòs)

void escriureCuaParInt(queue<ParInt> c);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements

#endif
