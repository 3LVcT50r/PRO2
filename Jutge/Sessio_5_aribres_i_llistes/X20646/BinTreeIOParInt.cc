#include <iostream>
#include "BinTreeIOParInt.hh"
using namespace std;

void read_bintree_parint(BinTree<ParInt>& a) {
  
  ParInt p;

  if (p.llegir()) {

    BinTree<ParInt> izq;
    read_bintree_parint(izq);
    BinTree<ParInt> der;
    read_bintree_parint(der);

    a = BinTree<ParInt> (p, izq, der);
  }
}


/*
void write_bintree_parint(const BinTree<ParInt>& a) {

  if (not a.empty()) {
    ParInt p = a.value();

    write_bintree_parint(a.left());
    cout << " " << p;
    write_bintree_parint(a.right());
  }
}
*/