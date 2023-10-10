#include "Jugador.hh"



Jugador::Jugador(){
  puntos = 0;
  torneos_disputados = 0;
  partidos_ganados = 0;
  partidos_perdidos = 0;
  sets_ganados = 0;
  sets_perdidos = 0;
  juegos_ganados = 0;
  juegos_perdidos = 0;
}

Jugador::Jugador(int pos){
  posicion = pos;
  puntos = 0;
  torneos_disputados = 0;
  partidos_ganados = 0;
  partidos_perdidos = 0;
  sets_ganados = 0;
  sets_perdidos = 0;
  juegos_ganados = 0;
  juegos_perdidos = 0;

}

void Jugador::modificar_posicion(int pos){
    posicion = pos;
}

void Jugador::modificar_puntos(int p){
    puntos += p;
}

void Jugador::modificar_torneos_disputados(int t){
    torneos_disputados += t;
}

void Jugador::modificar_pg(int pg){
    partidos_ganados += pg;
}

void Jugador::modificar_pp(int pp){
    partidos_perdidos += pp;
}

void Jugador::modificar_sets(int sg, int sp){
    sets_ganados += sg;
    sets_perdidos += sp;
}

void Jugador::modificar_juegos(int jg, int jp){
    juegos_ganados += jg;
    juegos_perdidos += jp;
}

int Jugador::consultar_posicion() const{
  return posicion;
}

int Jugador::consultar_puntos() const{
  return puntos;
}

void Jugador::escribir() const{
    cout << " Rk:"<< posicion << " Ps:" << puntos << " Ts:" << torneos_disputados << " WM:"
    << partidos_ganados << " LM:" << partidos_perdidos << " WS:" << sets_ganados << " LS:"
    << sets_perdidos << " WG:" << juegos_ganados << " LG:" << juegos_perdidos << endl;
}




