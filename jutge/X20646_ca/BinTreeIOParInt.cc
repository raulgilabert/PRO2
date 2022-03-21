#include "BinTreeIOParInt.hh"
#include "BinTree.hh"

void read_bintree_parint(BinTree<ParInt>& a) {
    ParInt p;
    if (p.llegir()) {
	BinTree<ParInt> left;
	BinTree<ParInt>right;

	read_bintree_parint(left);
	read_bintree_parint(right);

	a = BinTree<ParInt> (p, left, right);
    }
}
