// exemple d'us de la classe Llista

#include "LlistaIOint.hh"

int main(){
  Llista<int> l;
  cout << "Entra llista naturals (acabada per -1): " << endl;
  llegir_llista_int(l,-1);
  int x = l.suma();
  cout << "suma de la llista: " << x << endl;
}
