#include "Categorias.hh"
#include <iostream>
#include <vector>

using namespace std;

Categorias::Categorias() {
  /*Categ cat;
  cat.nombre = "";
  cat.puntos_totales = 0;*/
}

Categorias::~Categorias() {}
/*
void Categorias::mod_puntos_categoria(int c, int p) {

  lcat.at(c).puntos_totales = p;

}
*/
string Categorias::cons_nombre(int c) const {

  /*map<int,Categ>::const_iterator it = lcat.find(c);
  return it->second.nombre;*/

  return nom[c-1];
}

int Categorias::cons_puntos_por_nivel(int c, int k) const {
  /*map<int,Categ>::const_iterator it = lcat.find(c);
  return it->second.puntos_niveles[k];*/

  return p_lvl[c-1][k-1];
}
/*
int Categorias::cons_puntos_totales_por_cat(int c) const {
  map<int,Categ>::const_iterator it = lcat.find(c);
  return it->second.puntos_totales;
}
*/
void Categorias::leer(int c, int k) {

  /*numero_categorias = c;

  for (int i = 1; i <= c; ++i) {
    Categ cat;
    cin >> cat.nombre;
    cat.puntos_totales = 0;
    vector<int> v(k, 0);
    cat.puntos_niveles = v;
    lcat.insert(make_pair(i, cat));
  }

  for (int i = 1; i <= c; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> lcat[i].puntos_niveles[j];
    }
  }
*/
  vector<string> o(c);

  numero_categorias = c;

  for (int i = 0; i < c; ++i) {
    string n;
    cin >> n;
    o[i] = n;
  }
  nom = o;

  Matriz t(c, vector<int>(k));
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < k; ++j) {
      int l;
      cin >> l;
      t[i][j] = l;
    }
  }
  p_lvl = t;
}

void Categorias::listar_categorias() const {
  /*
  map<int,Categ>::const_iterator it = lcat.find(1);
  int k = it->second.puntos_niveles.size();

  cout << numero_categorias << " " << k << endl;

  for (map<int,Categ>::const_iterator it = lcat.begin(); it != lcat.end(); ++it) {
    cout << it->second.nombre;

    for (int j = 0; j < k; ++j) {
      cout << " " << it->second.puntos_niveles[j];
    }

    cout << endl;
  }
*/
  int col = p_lvl[0].size();
  cout << numero_categorias << ' ' << p_lvl[0].size() << endl;
  for (int i = 0; i < numero_categorias; ++i) {
    cout << nom[i];
    for (int j = 0; j < col; ++j) {
      cout << ' ' << p_lvl[i][j];
    }
    cout << endl;
  }
}