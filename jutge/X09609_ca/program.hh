/* Pre: p.i. = A, asub es buit
 * Post: si A conte x, asub es el subrarbre d'A resultat de la cerca;
 * si A no conte x, asub es buit */

void sub_arrel(Arbre& asub, const T& x) {
    int min_dist = -1;
    node_arbre* node_search = NULL;
    search(node_search, primer_node, x, 0, min_dist);

    node_arbre* sub_tree_ptr = copia_node_arbre(node_search);
    asub.primer_node = sub_tree_ptr;
}

void search(node_arbre* &m, node_arbre* n, const T& x, int dist,
	int& min_dist) {
    if (n != NULL) {
	if (n->info == x and (dist <= min_dist or min_dist == -1)) {
	    m = n;
	    min_dist = dist;
	}

	search(m, n->segE, x, ++dist, min_dist);
	search(m, n->segD, x, ++dist, min_dist);
    }
}
