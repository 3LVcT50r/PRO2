/**
 * @mainpage Circuito de torneos de tenis.
  
 En este programa modular se ofrece una simulación de la gestión deportiva y cálculo del ranking de un circuito de torneos de tenis.
 Se introducen las clases <em>Jugador</em>, <em>Torneo</em>, <em>Lista_Jugadores</em>, <em>Lista_Torneos</em> y <em>Lista_Categorias</em>.
*/

/** @file main.cc
    @brief Programa principal para la práctica <em>Circuito de torneos de tenis</em>.
*/

#include "Lista_Jugadores.hh"
#include "Lista_Torneos.hh"
#include "Categorias.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif

/** @brief Programa principal para la práctica <em>Circuito de torneos de tenis</em>.
*/
int main() {

  //Inicializacion de las categorias
  int c, k_lvl;
  cin >> c >> k_lvl;
  Categorias cat;
  cat.leer(c, k_lvl);

  //Inicializacion de los torneos
  int ntorn;
  cin >> ntorn;
  Lista_Torneos ltorn;
  ltorn.leer(ntorn);

  //Inicializacion de los jugadores
  int njug;
  cin >> njug;
  Lista_Jugadores ljug;
  ljug.leer(njug);


  //Operaciones y funciones
  string function;
  cin >> function;
  while (function != "fin") {

    //Nuevo Jugador
    if (function == "nj" or function == "nuevo_jugador") {
      string p;
      cin >> p;
      cout << '#' << function << ' ' << p << endl;
      if (ljug.identificador_jugador(p)) cout << "error: ya existe un jugador con ese nombre" << endl;
      else {
        ljug.nuevo_jugador(p);
        cout << ljug.num_jugadores() << endl;
      }
    }

    //Nuevo Torneo
    else if (function == "nt" or function == "nuevo_torneo") {
      string t;
      int ct;
      cin >> t >> ct;
      cout << '#' << function << ' ' << t << ' ' << ct << endl;
      if (1 > ct or ct > c) cout << "error: la categoria no existe" << endl;
      else {
        if (ltorn.identificador_torneo(t)) cout << "error: ya existe un torneo con ese nombre" << endl;
        else {
          ltorn.nuevo_torneo(t, c);
          cout << ltorn.num_torneos() << endl;
        }
      }
    }

    //Baja jugador
    else if (function == "bj" or function == "baja_jugador") {
      string p;
      cin >> p;
      cout << '#' << function << ' ' << p << endl;
      if (ljug.identificador_jugador(p)) {
        ljug.baja_jugador(p);
        cout << ljug.num_jugadores() << endl;
      } else cout << "error: el jugador no existe" << endl;
    }

    //Baja Torneo
    else if (function == "bt" or function == "baja_torneo") {
      string t;
      cin >> t;
      cout << '#' << function << ' ' << t << endl;
      if (ltorn.identificador_torneo(t)) {
        ltorn.baja_torneo(t);
        cout << ltorn.num_torneos() << endl;
      } else cout << "error: el torneo no existe" << endl;
    }

    //Iniciar Torneo
    else if (function == "it" or function == "iniciar_torneo") {    
      string t;
      cin >> t;
      cout << '#' << function << ' ' << t << endl;
      int n;
      cin >> n;
      ltorn.iniciar_torneo(t, n, ljug);
    }

    //Finalizar Torneo
    else if (function == "ft" or function == "finalizar_torneo") {
      string t;
      cin >> t;
      ltorn.finalizar_torneo();
    }

    //Listar Ranking
    else if (function == "lr" or function == "listar_ranking") {
      cout << '#' << function << endl;
      ljug.listar_ranking();
    }

    //Listar Jugadores
    else if (function == "lj" or function == "listar_jugadores") {
      cout << '#' << function << endl;
      ljug.listar_jugadores();
    }

    //Consultar Jugador
    else if (function == "cj" or function == "consultar_jugador") {
      string p;
      cin >> p;
      cout << '#' << function << ' ' << p << endl;;
      if (ljug.identificador_jugador(p)) {
        ljug.listar_jugador(p);
      } else cout << "error: el jugador no existe" << endl;
    }

    //Listar Torneos
    else if (function == "lt" or function == "listar_torneos") {
      cout << '#' << function << endl;
      ltorn.listar_torneos(cat);
    }

    //Listar Categorias
    else if (function == "lc" or function == "listar_categorias") {
      cout << '#' << function << endl;
      cat.listar_categorias();
    }

    cin >> function;
  }

}