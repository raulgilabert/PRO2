
int suma ()
  /* Pre: cert */ 
  /* Post: el resultat es la suma dels elements del p.i. */
  {
    int s = 0;
    node_llista* n = primer_node;
    while (n != NULL) {
      s += n->info;
      n = n->seg;
    }
    return s;
  }
