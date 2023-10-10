#include "Jugador.hh"
#include <iostream>

using namespace std;

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

Jugador::~Jugador(){}

void Jugador::mod_ranking(int r) {
  ranking = r;
}

void Jugador::mod_puntos(int pt) {
  puntos += pt;
}

void Jugador::mod_torn_jugados(int tj) {
  torn_jugados += tj;
}

void Jugador::mod_wm(int pg) {
  wm = pg;
}

void Jugador::mod_lm(int pp) {
  lm = pp;
}

void Jugador::mod_wg(int jg) {
  wg = jg;
}

void Jugador::mod_lg(int jp) {
  lg = jp;
}

void Jugador::mod_ws(int sg) {
  ws = sg;
}

void Jugador::mod_ls(int sp) {
  ls = sp;
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