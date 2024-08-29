/** @file Torneo.cc
    @brief Código de la clase Torneo
*/

#include "Torneo.hh"

//Private

void Torneo::arbol_emp(BinTree<int> &a, const vector<string> &v, int l, bool &cond) {

  //La condición es para poner espacios siempre que sea True

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
    arbol_emp(b, v, l+1, cond);
    cond = true;
    BinTree<int> c(z + 1 - a.value());
    arbol_emp(c, v, l+1, cond);
    cout << ')';
    a = BinTree<int> (a.value(), b, c);
  }
}

void Torneo::act_puntos_viejo_torneo(Lista_Jugadores &ljug) {
  int psize = ant_participantes.size();
  for (int i = 0; i < psize; ++i) {
    ljug.act_punt_jug(ant_participantes[i], ant_puntos_jugador[i]);
  }
  ljug.ordenar();
}

void Torneo::arbol_punt(BinTree<string> &a) {
  string result;
  cin >> result;
  if (result != "0") {
    BinTree<string> l;
    arbol_punt(l);
    BinTree<string> r;
    arbol_punt(r);
    a = BinTree<string>(result, l, r);
  }
}

int Torneo::winner(int a, int b, const string &x) {
  int sets_a = 0;
  int sets_b = 0;

  for (int i = 0; i < 3; ++i) {
    int puntos_a = x[4*i];
    int puntos_b = x[2+4*i];
    if (puntos_a == '1' and puntos_b == '0') return a;
    else if (puntos_a == '0' and puntos_b == '1') return b;
    else if (puntos_a > puntos_b) {
      ++sets_a;
      if (sets_a == 2) return a;
    } else {
      ++sets_b;
      if (sets_b == 2) return b;
    }
  }
  return 0;
}

void Torneo::arbol_res(BinTree<int> &a, const BinTree<int> &part, const BinTree<string> &punt) {
  if (not part.left().empty()) {
    BinTree<int> l;
    arbol_res(l, part.left(), punt.left());
    BinTree<int> r;
    arbol_res(r, part.right(), punt.right());
    a = BinTree<int>(winner(l.value(), r.value(), punt.value()), l, r);
  }
  else a = BinTree<int>(part.value());
}

void Torneo::mod_puntos(const BinTree<int> &res, int l) {
  if (not res.empty()) {
    if (est_local[res.value()-1][6] == 0) est_local[res.value()-1][6] += l;
    mod_puntos(res.left(), l+1);
    mod_puntos(res.right(), l+1);
  }
}

void Torneo::anadir_est_matriz(int &j1, int &j2, const string &puntos) {

  if (puntos == "1-0" or puntos == "0-1") {
    if (puntos[0] == '1') {
      est_local[j1][0] += 1;
      est_local[j2][1] += 1;
    } else {
      est_local[j1][1] += 1;
      est_local[j2][0] += 1;
    }
  } else {
    bool cond = false;
    int match1 = 0;
    int match2 = 0;
    for (int i = 0; i < 3 and not cond; ++i) {
      if (puntos[i*4] > puntos[i*4+2]) {
        est_local[j1][4] += 1;
        est_local[j2][5] += 1;
        ++match2;
      } else {
        est_local[j1][5] += 1;
        est_local[j2][4] += 1;
        ++match1;
      }
      est_local[j1][2] += (int(puntos[i*4]) - 48);
      est_local[j2][3] += (int(puntos[i*4]) - 48);
      est_local[j2][2] += (int(puntos[i*4+2]) - 48);
      est_local[j1][3] += (int(puntos[i*4+2]) - 48);

      if (match1 == 2 or match2 == 2) {
        cond = true;
        if (match1 == 2) {
          est_local[j1][1] += 1;
          est_local[j2][0] += 1;
        } else {
          est_local[j1][0] += 1;
          est_local[j2][1] += 1;
        }
      }
    }
  }
}

void Torneo::imprimir_res(const BinTree<int> &res, const BinTree<string> &punt, const vector<string> &part) {
  if (not res.left().empty()) {
    cout << '(';
    cout << res.left().value() << '.' << part[res.left().value() - 1];
    cout << " vs ";
    cout << res.right().value() << '.' << part[res.right().value() - 1];
    cout << ' ' << punt.value();

    int j1 = res.left().value() - 1;
    int j2 = res.right().value() - 1;
    string puntos = punt.value();
    anadir_est_matriz(j1, j2, puntos);

    imprimir_res(res.left(), punt.left(), part);
    imprimir_res(res.right(), punt.right(), part);
    cout << ')';
  }
}

void Torneo::imprimir_puntos(const vector<string> &part, const Matriz &est, vector<int> &punt, const Categorias &lcat) {
  int psize = part.size();
  for (int i = 0; i < psize; ++i) {
    int puntos = lcat.cons_puntos_por_nivel(cat, est[i][6]);
    punt[i] = puntos;
    if (puntos != 0) {
      cout << i+1 << '.' << part[i] << ' ' << puntos << endl;
    }
  }
}

//Public

Torneo::Torneo() {
  cat = 0;

  BinTree<int> a(1);
  part = a;
}

Torneo::Torneo(const int &c) {
  cat = c;

  BinTree<int> a(1);
  part = a;
}

void Torneo::inic_torneo(const vector<string> &v) {
  participantes = v;

  int l = 2;
  bool cond = false;
  arbol_emp(part, v, l, cond);
  cout << endl;
}

void Torneo::fini_torneo(Lista_Jugadores &ljug, const Categorias &lcat) {

  vector<int> p(participantes.size());
  puntos_jugador = p;

  //Resets
  BinTree<int> b;
  res = b;
  BinTree<string> c;
  punt = c;
  Matriz M(participantes.size(), vector<int>(7));
  est_local = M;

  arbol_punt(punt);
  arbol_res(res, part, punt);
  int l = 1;
  mod_puntos(res, l);
  imprimir_res(res, punt, participantes);
  cout << endl;

  imprimir_puntos(participantes, est_local, puntos_jugador, lcat);
  ljug.mod_estadisticas(participantes, est_local, puntos_jugador);
  if (ant_participantes.size() != 0) {
    act_puntos_viejo_torneo(ljug);
  }

  ant_participantes = participantes;
  ant_puntos_jugador = puntos_jugador;

  ljug.ordenar();
}

void Torneo::act_puntos_baja_jug(const string &p) {
  int psize = ant_participantes.size();
  for (int i = 0; i < psize; ++i) {
    if (p == ant_participantes[i]) ant_puntos_jugador[i] = 0;
  }
}

void Torneo::act_est_baja_torneo(Lista_Jugadores &ljug) {
  if (ant_participantes.size() != 0) {
    int psize = ant_participantes.size();
    for (int i = 0; i < psize; ++i) {
      ljug.act_punt_jug(ant_participantes[i], ant_puntos_jugador[i]);
    }
  }
}

bool Torneo::hay_historial() const {
  if (ant_participantes.size() != 0) return true;
  else return false;
}

int Torneo::cons_categoria() const {
  return cat;
}
