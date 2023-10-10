/**
 * @mainpage Circuito de torneos de tenis.
  
 En este programa modular se ofrece una simulación de la gestión deportiva y cálculo del ranking de un circuito de torneos de tenis.
 Se introducen las clases <em>Jugador</em>, <em>Torneo</em>, <em>Lista_Jugadores</em>, <em>Lista_Torneos</em> y <em>Categorias</em>.

 Este programa concede una serie de instrucciones:
 - Primero de todo, se leerán las categorías, torneos y jugadores iniciales antes de empezar a usar el programa
 - Después, dispones de una serie de operaciones las cuales puedes acceder mediantes la siguientes funciones por consola:

    - Nuevo_Jugador (nuevo_jugador o nj): añade un jugador a la lista de jugadores iniciada previamente. A este se le tiene que añadir un nombre. Si este ya está existe, saltará un error.
    - Nuevo_Torneo (nuevo_torneo o nt): añade un torneo a la lista de torneos iniciada previamentemente. A este se le tiene que añadir un nombre y una categoría. Si este nombre ya existe o la categoría no está definida, saltará error.
    - Baja_Jugador (baja_jugador o bj): da de baja un jugador y actualiza la puntuación de este en todos los torneos donde haya estado inscrito. A este se le tiene que añadir el identificador del juagdor el cual se quiere remover. Si el identificador del jugador no existe, saltará error.
    - Baja_Torneo (baja_torneo o bt): da de baja un torneo, actualizando todos los puntos de los jugadores que hayan estado inscritos en este torneo. A este se le tiene que añadir el identificador del torneo el cual se quiere remover. Si el idenficador del torneo no existe, saltará error.
    - Inicar_Torneo (iniciar_torneo o it): inicia un torneo y imprime el los emparejamientos de este. Primero se tiene que añadir el nombre del torneo que se quiere añadir, seguido del numero de jugadores "n" que se quiere añadir y por último el ranking de los "n" jugadores en orden creciente.
    - Finalizar_Torneo (finalizar_torneo o ft): finaliza un torneo y imprime el cuadro de resultados y los puntos conseguido por lo jugadores inscritos, actualizando los puntos de dichos jugadores, tanto para lo que han jugado como los inscritos anterior mente que no han jugado.
    - Listar_Rankign (listar_ranking o lr): primero te dice cuantos jugadores hay seguido de el ranking en orden creciente del ranking imprimiendo el numero de ranking, el nombre del jugador y los puntos conseguidos.
    - Listar_Jugadores (listar_jugadores o lj): lista los jugadors en orden alfabetico mostrando el ranking, los puntos ,los torneos juagdos, los partidos tanto ganados como perdidos, los setts tanto ganados como perdidos y los juegos tanto ganados como perdidos de cada jugador.
    - Consultar_Jugador (consultar_jugador o cj): lista solo 1 jugador imprimiendo las mismas características de "Listar Jugadores" pero solo con un jugador. A este se le tiene que añadir el nombre del jugador.
    - Listar_Torneos (listar_torneos o lt): primero te dice cuantos torneos hay seguido de los torneos imprimiendo los nombres de los torneos con su respectivos nombres de las categorías a las que estan asociadas cada torneo.
    - Por último (fin) hace que finalice el programa.
*/

/** @file program.cc

    @brief Programa principal para la práctica <em>Circuito de torneos de tenis</em>.

    Este es el programa donde se inicia el programa y donde se escocje las operaciones.
    Estamos suponiendo que una serie de datos leídos siempre seran correctos, ya que, menos en las operaciones dichas en la página principal, no se incluye comprobaciones al respecto.
*/

#include "Lista_Jugadores.hh"
#include "Lista_Torneos.hh"
#include "Categorias.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif

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
          ltorn.nuevo_torneo(t, ct);
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
        ltorn.act_baja_jugador(p);
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
        ltorn.baja_torneo(t, ljug);
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
      cout << '#' << function << ' ' << t << endl;
      ltorn.finalizar_torneo(t, ljug, cat);
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
        ljug.consultar_jugador(p);
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

    //Puntos Torneo
    else if (function == "pt" or function == "puntos_torneo") {
      string t;
      cin >> t;
      cout << "#" << function << ' ' << t << endl;
      if (ltorn.identificador_torneo(t)) {
        if (ltorn.cons_torneo_hay_historial(t)) {
          if (not ltorn.cons_torneo_iniciado(t)) {
            ltorn.puntos_torneo(t);
          } else {
            cout << "error: torneo en juego" << endl;
          }
        } else {
          cout << "error: torneo no disputado" << endl;
        }
      } else {
        cout << "error: el torneo no existe" << endl;
      }
    }

    else if (function == "mjg" or function == "mejor_jugador_games") {
      cout << '#' << function << endl;
      ljug.mejor_jg();
    }

    cin >> function;
  }
}