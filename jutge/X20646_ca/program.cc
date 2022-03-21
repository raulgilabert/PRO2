#include <iostream>
#include "BinTreeIOParInt.hh"

int find_num(const BinTree<ParInt>& a, int n, int prof, int& comp) {
    if (not a.empty()) {
    
	if (a.value().primer() == n) {
	    comp = a.value().segon();
	    return prof;
	}

	int left = find_num(a.left(), n, ++prof, comp);
	if (left != -1) return left;
	int right = find_num(a.right(), n, prof, comp);
	if (right != -1) return right;
    }

    return -1;
}


int main() {
    BinTree<ParInt> tree;
    read_bintree_parint(tree);

    int num;
    while (cin >> num) {
	int comp;
	int prof = find_num(tree, num, 0, comp);

	if (prof != -1) {
	    cout << num << ' ' << comp << ' ' << prof << endl;
	} else
	    cout << -1 << endl;
    }
}

