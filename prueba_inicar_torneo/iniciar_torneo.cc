#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "BinTree.hh"
using namespace std;

vector<string> leer_vector(const int &n) {
  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    v[i] = x;
  }
  return v;
}

void arbol(BinTree<int> &a, const vector<string> v, int l, bool cond) {

  int sizev = v.size();
  int z = pow(2, l - 1);
  int pote = pow(2, l - 2);

  if ((sizev) < (z + 1 - a.value())) {
    if (a.value() <= pote/2) cout << a.value() << '.' << v[a.value() - 1];
    else cout << ' ' << a.value() << '.' << v[a.value() - 1];
  } 
  else {
    BinTree<int> b(a.value());
    if (cond) cout << ' ';
    cond = false;
    cout << '(';
    arbol(b, v, l+1, cond);
    cond = true;
    BinTree<int> c(z + 1 - a.value());
    arbol(c, v, l+1, cond);
    cout << ')';
    a = BinTree<int> (a.value(), b, c);
  }
}

void arbol2(BinTree<int> &a, BinTree<int> &part, BinTree<string> &punt) {

  if (not part.left().empty()) {
    BinTree<int> l;
    arbol2(l, part.left(), punt.left());
    BinTree<int> r;
    arbol2(r, part.right(), punt.right());
    a = BinTree<int>(ganador(part, punt), l, r);
  }
  else {
    a = BinTree<int>(part.value());
  }
}

int ganador(BinTree<int> &part, BinTree<string> &punt) {

}

int main() {
  int n;
  cin >> n;
  vector<string> v = leer_vector(n);
  BinTree<int> a(1);
  int l1 = 2;
  bool cond = false;
  arbol(a, v, l1, cond);
  cout << endl;


}