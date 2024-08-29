/** @file Jugador.cc
    @brief Código de la clase Jugador
*/

#include "Jugador.hh"

Jugador::Jugador() {

  ranking = 0;
  puntos = 0;
  torn_jugados = 0;
  wm = 0;
  lm = 0;
  wg = 0;
  lg = 0;
  ws = 0;
  ls = 0;
}

void Jugador::mod_ranking(const int &r) {
  ranking = r;
}

void Jugador::mod_puntos(const int &pt) {
  puntos += pt;
  if (puntos < 0) puntos = 0;
}

void Jugador::mod_torn_jugados(const int &tj) {
  torn_jugados += tj;
}

void Jugador::mod_wm(const int &pg) {
  wm += pg;
}

void Jugador::mod_lm(const int &pp) {
  lm += pp;
}

void Jugador::mod_wg(const int &jg) {
  wg += jg;
}

void Jugador::mod_lg(const int &jp) {
  lg += jp;
}

void Jugador::mod_ws(const int &sg) {
  ws += sg;
}

void Jugador::mod_ls(const int &sp) {
  ls += sp;
}

int Jugador::cons_ranking() const {
  return ranking;
}

int Jugador::cons_puntos() const {
  return puntos;
}

int Jugador::cons_torn_jugados() const {
  return torn_jugados;
}

int Jugador::cons_wm() const {
  return wm;
}

int Jugador::cons_lm() const {
  return lm;
}

int Jugador::cons_wg() const {
  return wg;
}

int Jugador::cons_lg() const {
  return lg;
}

int Jugador::cons_ws() const {
  return ws;
}

int Jugador::cons_ls() const {
  return ls;
}