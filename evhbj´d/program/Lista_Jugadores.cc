#include "Lista_Jugadores.hh"
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

Lista_Jugadores::Lista_Jugadores() {
  Jugador jug;
  string ide = "";
  numero_jugadores = 0;
  vector<pair<string,int>> p;
  v = p;
}

Lista_Jugadores::~Lista_Jugadores() {}

void Lista_Jugadores::nuevo_jugador(const string &p) {
  
  Jugador njug;
  njug.mod_ranking(numero_jugadores + 1);
  ljug.insert(make_pair(p, njug));

  pair<string,int> l;
  l.first = p;
  l.second = 0;
  v.push_back(l);

  ++numero_jugadores;
}

void Lista_Jugadores::baja_jugador(const string &p) {

  map<string,Jugador>::iterator ite = ljug.find(p);
  int rank = ite->second.cons_ranking();
  ljug.erase(ite);
  for (map<string,Jugador>::iterator it = ljug.begin(); it != ljug.end(); ++it) {
    if (it->second.cons_ranking() > rank) it->second.mod_ranking(it->second.cons_ranking() - 1);
  }
  for (int i = rank-1; i < numero_jugadores - 1; ++i) {
    v[i] = v[i+1];
  }
  v.pop_back();

  --numero_jugadores;
}

int Lista_Jugadores::num_jugadores() const {
  return numero_jugadores;
}

bool Lista_Jugadores::identificador_jugador(const string &ide) const {
  map<string,Jugador>::const_iterator it = ljug.find(ide);
  if (it != ljug.end()) return true;
  else return false;
}

map<string,Jugador> Lista_Jugadores::mapa() {
  return ljug;
}

void Lista_Jugadores::leer(int j) {

  numero_jugadores = j;

  vector<pair<string,int>> t(j);

  for (int i = 0; i < j; ++i) {
    string ide;
    cin >> ide;
    Jugador jug;
    jug.mod_ranking(i+1);
    ljug.insert(make_pair(ide, jug));

    pair<string,int> p;
    p.first = ide;
    p.second = 0;
    t[i] = p;
  }
  v = t;
}

void Lista_Jugadores::listar_ranking() const {

/*  vector<pair<string,int>> v(numero_jugadores);

  for (int i = 0; i < numero_jugadores; ++i) {
    bool cond = false;
    map<string,Jugador>::const_iterator it = ljug.begin();
    while (not cond) {
      if (it->second.cons_ranking() == i + 1) {
        cond = true;
        pair<string,int> p;
        p.first = it->first;
        p.second = it->second.cons_puntos();
        v[i] = p;
      }
      ++it;
    }
  }

  for (int i = 0; i < numero_jugadores; ++i) {
    cout << i + 1 << ' ' << v[i].first << ' ' << v[i].second << endl;
  }
  */

  for (int i = 0; i < numero_jugadores; ++i) {
    cout << i+1 << ' ' << v[i].first << ' ' << v[i].second << endl;
  }
}

void Lista_Jugadores::listar_jugadores() const {
  cout << numero_jugadores << endl;

  for (map<string,Jugador>::const_iterator it = ljug.begin(); it != ljug.end(); ++it) {
    cout << it->first << ' ';
    cout << "Rk:" << it->second.cons_ranking() << ' ';
    cout << "Ps:" << it->second.cons_puntos() << ' ';
    cout << "Ts:" << it->second.cons_torn_jugados() << ' ';
    cout << "WM:" << it->second.cons_wm() << ' ';
    cout << "LM:" << it->second.cons_lm() << ' ';
    cout << "WS:" << it->second.cons_ws() << ' ';
    cout << "LS:" << it->second.cons_ls() << ' ';
    cout << "WG:" << it->second.cons_wg() << ' ';
    cout << "LG:" << it->second.cons_lg() << endl;
  }
}

void Lista_Jugadores::listar_jugador(const string &p) const {

  map<string,Jugador>::const_iterator it = ljug.find(p);
  cout << it->first << ' ';
  cout << "Rk:" << it->second.cons_ranking() << ' ';
  cout << "Ps:" << it->second.cons_puntos() << ' ';
  cout << "Ts:" << it->second.cons_torn_jugados() << ' ';
  cout << "WM:" << it->second.cons_wm() << ' ';
  cout << "LM:" << it->second.cons_lm() << ' ';
  cout << "WS:" << it->second.cons_ws() << ' ';
  cout << "LS:" << it->second.cons_ls() << ' ';
  cout << "WG:" << it->second.cons_wg() << ' ';
  cout << "LG:" << it->second.cons_lg() << endl;
}