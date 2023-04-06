#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a) {
    Estudiant est;
    est.llegir();

    if (est.consultar_DNI() != 0) {
	BinTree<Estudiant> left;
	read_bintree_est(left);
	BinTree<Estudiant> right;
	read_bintree_est(right);

	BinTree<Estudiant> a(est, left, right);
    } else
	BinTree<Estudiant> a;
}
