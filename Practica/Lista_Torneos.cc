/** @file Lista_Torneos.cc
    @brief Código de la clase Lista_Torneos
*/

#include "Lista_Torneos.hh"

Lista_Torneos::Lista_Torneos() {
  Torneo torn;
  string ide = "";
  numero_torneos = 0;
}

void Lista_Torneos::nuevo_torneo(const string &t, const int &c) {
  Torneo torn(c);
  ltorn.insert(make_pair(t, torn));
  ++numero_torneos;
}

void Lista_Torneos::baja_torneo(const string &t, Lista_Jugadores &ljug) {
  map<string,Torneo>::iterator it = ltorn.find(t);
  if (it->second.hay_historial()) {
    it->second.act_est_baja_torneo(ljug);
    ljug.ordenar();
  }

  ltorn.erase(it);
  --numero_torneos;
}

void Lista_Torneos::iniciar_torneo(const string &t, const int &n, Lista_Jugadores &ljug) {
  
  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    int rnk;
    cin >> rnk;
    v[i] = ljug.cons_nombre_jugador(rnk);
  }
 
  map<string,Torneo>::iterator it = ltorn.find(t);
  it->second.inic_torneo(v);
}

void Lista_Torneos::finalizar_torneo(const string &t, Lista_Jugadores &ljug, const Categorias &lcat) {
  map<string,Torneo>::iterator it = ltorn.find(t);
  it->second.fini_torneo(ljug, lcat);
}

void Lista_Torneos::act_baja_jugador(const string &p) {
  for (map<string,Torneo>::iterator it = ltorn.begin(); it != ltorn.end(); ++it) {
    if (it->second.hay_historial()) it->second.act_puntos_baja_jug(p);
  }
}

bool Lista_Torneos::identificador_torneo(const string &t) const {
  map<string,Torneo>::const_iterator it = ltorn.find(t);
  if (it != ltorn.end()) return true;
  else return false;
}

int Lista_Torneos::num_torneos() const {
  return numero_torneos;
}

void Lista_Torneos::leer(const int &n) {

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