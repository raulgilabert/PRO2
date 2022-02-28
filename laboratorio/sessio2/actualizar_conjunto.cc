#include "Cjt_estudiants.hh"

void actualizar(Cjt_estudiants& cjt1, const Cjt_estudiants& cjt2) {
    int num = cjt1.mida();

    for (int i = 0; i < num; ++i) {
	Estudiant est_conj1 = cjt1.consultar_iessim(i + 1);
	Estudiant est_conj2 = cjt2.consultar_iessim(i + 1);
    }
}

int main() {
    Cjt_estudiants conjunto1;
    conjunto1.llegir();

    Cjt_estudiants conjunto2;
    conjunto2.llegir();

    actualizar(conjunto1, conjunto2);
}
