#include "Torneo.hh"

using namespace std;

Torneo::Torneo() {
  puntos_totales = 0;
  esta_iniciado = false;
  cat = 0;
  BinTree<int> a(1);
  arbol_emparejamientos = a;
}

Torneo::Torneo(int c) {
  puntos_totales = 0;
  esta_iniciado = false;
  cat = c;
  BinTree<int> a(1);
  arbol_emparejamientos = a;
}

Torneo::~Torneo() {}

void Torneo::mod_estado_torneo(bool estado) {
  esta_iniciado = estado;
}

void Torneo::mod_puntos_totales(int p) {
  puntos_totales = p;
}

void Torneo::ini_torneo(const vector<string> &v) {
  esta_iniciado = true;
  int l = 2;
  bool cond = false;
  arbol(arbol_emparejamientos, v, l, cond);
  cout << endl;
}

bool Torneo::cons_estado_torneo() const {
  return esta_iniciado;
}

int Torneo::cons_puntos_totales() const {
  return puntos_totales;
}

int Torneo::cons_categoria() const {
  return cat;
}