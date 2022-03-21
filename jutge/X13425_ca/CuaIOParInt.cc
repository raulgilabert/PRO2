#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c) {
    ParInt par;
    
    while (par.llegir()) 
	c.push(par);
}

void escriureCuaParInt(queue<ParInt> c){
    while (not c.empty()) {
	c.front().escriure();
	c.pop();
    }
}
