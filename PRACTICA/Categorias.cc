/** @file Categorias.cc
    @brief Código de la clase Categorias
*/ 

#include "Categorias.hh"

Categorias::Categorias() {
  numero_categorias = 0;
}

string Categorias::cons_nombre(const int &c) const {

  return nom[c-1];
}

int Categorias::cons_puntos_por_nivel(const int &c, const int &k) const {
  
  return p_lvl[c-1][k-1];
}

void Categorias::leer(const int &c, const int &k) {

  vector<string> v_aux(c);

  numero_categorias = c;

  for (int i = 0; i < c; ++i) {
    string n;
    cin >> n;
    v_aux[i] = n;
  }
  nom = v_aux;

  Matriz M(c, vector<int>(k));
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < k; ++j) {
      int l;
      cin >> l;
      M[i][j] = l;
    }
  }
  p_lvl = M;
}

void Categorias::listar_categorias() const {
  
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