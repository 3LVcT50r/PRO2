/** @file Lista_Jugadores.cc
    @brief Código de la clase Lista_Jugadores
*/

#include "Lista_Jugadores.hh"

//Private

bool Lista_Jugadores::comp(const Ranking &j1, const Ranking &j2) {
  if (j1.punti == j2.punti) return j1.ranki < j2.ranki;
  else return j1.punti > j2.punti;
}

//Public

Lista_Jugadores::Lista_Jugadores() {
  Jugador jug;
  string ide = "";
  numero_jugadores = 0;
  ranking = {};
}

void Lista_Jugadores::nuevo_jugador(const string &p) {
  
  Jugador njug;
  njug.mod_ranking(numero_jugadores + 1);
  ljug.insert(make_pair(p, njug));

  Ranking j_rnk;
  j_rnk.nombre = p;
  j_rnk.punti = 0;
  j_rnk.ranki = numero_jugadores +1;
  ranking.push_back(j_rnk);

  numero_jugadores = ranking.size();
}

void Lista_Jugadores::baja_jugador(const string &p) {

  map<string,Jugador>::iterator ite = ljug.find(p);
  int rank = ite->second.cons_ranking();
  ljug.erase(ite);

  //Actualizar vector Ranking
  for (int i = rank-1; i < numero_jugadores-1; ++i) {
    ljug[ranking[i+1].nombre].mod_ranking(ljug[ranking[i+1].nombre].cons_ranking() - 1);
    --ranking[i+1].ranki;
    ranking[i] = ranking[i+1];
  }
  ranking.pop_back();

  numero_jugadores = ranking.size();
}

void Lista_Jugadores::act_punt_jug(const string &part, const int &punt) {
  map<string,Jugador>::iterator it = ljug.find(part);
  if (it != ljug.end()) {
    it->second.mod_puntos(-punt);
    int i = it->second.cons_ranking();
    ranking[i-1].punti -= punt;
  }
}

void Lista_Jugadores::mod_estadisticas(const vector<string> &v, const Matriz &est, const vector<int> &puntos) {

  int psize = v.size();
  map<string,Jugador>::iterator it = ljug.begin();
  for (int i = 0; i < psize; ++i) {
    it = ljug.find(v[i]);
    it->second.mod_torn_jugados(1);
    it->second.mod_wm(est[i][0]);
    it->second.mod_lm(est[i][1]);
    it->second.mod_wg(est[i][2]);
    it->second.mod_lg(est[i][3]);
    it->second.mod_ws(est[i][4]);
    it->second.mod_ls(est[i][5]);
    it->second.mod_puntos(puntos[i]);

    int rank_anterior = it->second.cons_ranking();
    ranking[rank_anterior - 1].punti += puntos[i];
  }
}

void Lista_Jugadores::ordenar() {
  sort(ranking.begin(), ranking.end(), comp);
  for (int i = 0; i < numero_jugadores; ++i) {
    ljug[ranking[i].nombre].mod_ranking(i+1);
    ranking[i].ranki = i+1;
  }
}

string Lista_Jugadores::cons_nombre_jugador(const int &r) const {
  return ranking[r-1].nombre;
}

int Lista_Jugadores::num_jugadores() const {
  return numero_jugadores;
}

bool Lista_Jugadores::identificador_jugador(const string &ide) const {
  map<string,Jugador>::const_iterator it = ljug.find(ide);
  if (it != ljug.end()) return true;
  else return false;
}

void Lista_Jugadores::mejor_jg() {

  double mpjg = -1;
  string nombre = "";
  int ranking = 1;

  for (map<string,Jugador>::const_iterator it = ljug.begin(); it != ljug.end(); ++it) {
    double juegos_g = it->second.cons_wg();
    double total_jugos = juegos_g + it->second.cons_lg();

    if (total_jugos != 0) { //Si es 0, dará error, porque no se puede dividir entre 0
      
      double pjg = (juegos_g / total_jugos) *100;

      if (pjg > mpjg) {
        mpjg = pjg;
        nombre = it->first;
        ranking = it->second.cons_ranking();
      } 
      else if (pjg == mpjg) {
        if (it->second.cons_ranking() <= ranking) {
          mpjg = pjg;
          nombre = it->first;
          ranking = it->second.cons_ranking();
        }
      }
    }
  }

  cout.setf(ios::fixed);
  cout .precision(4);
  cout << nombre << ' ' << mpjg << endl;
}

void Lista_Jugadores::leer(const int &j) {

  numero_jugadores = j;

  vector<Ranking> v_rnk(j);

  for (int i = 0; i < j; ++i) {
    string ide;
    cin >> ide;
    Jugador jug;
    jug.mod_ranking(i+1);
    ljug.insert(make_pair(ide, jug));

    Ranking j_rnk;
    j_rnk.nombre = ide;
    j_rnk.punti = 0;
    j_rnk.ranki = i+1;

    v_rnk[i] = j_rnk;
  }
  ranking = v_rnk;
}

void Lista_Jugadores::listar_ranking() const {

  for (int i = 0; i < numero_jugadores; ++i) {
    cout << i+1 << ' ' << ranking[i].nombre << ' ' << ranking[i].punti << endl;
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

void Lista_Jugadores::consultar_jugador(const string &p) const {

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