#include "Lista_Torneos.hh"
#include <iostream>
#include <utility>
using namespace std;

Lista_Torneos::Lista_Torneos() {
  Torneo torn;
  string ide = "";
  numero_torneos = 0;
}

Lista_Torneos::~Lista_Torneos() {}

void Lista_Torneos::nuevo_torneo(const string &t, int c) {
  Torneo torn(c);
  ltorn.insert(make_pair(t, torn));
  ++numero_torneos;
}

void Lista_Torneos::baja_torneo(const string &t) {
  ltorn.erase(t);
  --numero_torneos;

  //FALTA QUITAR LOS PUNTOS A LOS JUGADORES
}

void Lista_Torneos::iniciar_torneo(const string &t, int n, Lista_Jugadores &ljug) {
  
  vector<string> v(n);
  for (int i = 0; i < n ; ++i) {
    int r;
    cin >> r;
    map<string,Jugador> mapi = ljug.mapa();
    map<string,Jugador>::iterator ite = mapi.begin();
    bool cond = false;
    while (not cond and ite != mapi.end()) {

      if (ite->second.cons_ranking() == r) {
        cond = true;
        v[i] = ite->first;
      }

      ++ite;
    }
  }

  map<string,Torneo>::iterator it = ltorn.find(t);
  it->second.ini_torneo(v);
}

void Lista_Torneos::finalizar_torneo() {}

bool Lista_Torneos::identificador_torneo(const string &t) const {
  map<string,Torneo>::const_iterator it = ltorn.find(t);
  if (it != ltorn.end()) return true;
  else return false;
}

int Lista_Torneos::num_torneos() const {
  return numero_torneos;
}

Torneo Lista_Torneos::consultar_torneo(const string &t) const {
  map<string,Torneo>::const_iterator it = ltorn.find(t);
  return it->second;
}

void Lista_Torneos::leer(int n) {

  numero_torneos = n;

  for (int i = 0; i < n; ++i) {
    string ide;
    cin >> ide;

    int cat;
    cin >> cat;
    Torneo torn(cat);

    ltorn.insert(make_pair(ide,torn));
  }
}

void Lista_Torneos::listar_torneos(const Categorias &cat) const {
  cout << numero_torneos << endl;

  for (map<string,Torneo>::const_iterator it = ltorn.begin(); it != ltorn.end(); ++it) {
    cout << it->first << ' ';
    cout << cat.cons_nombre(it->second.cons_categoria()) << endl;
  }
}