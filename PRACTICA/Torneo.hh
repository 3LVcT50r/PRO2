/** @file Torneo.hh
    @brief Especificacion de la clase Torneo
*/

#ifndef _TORNEO_HH_
#define _TORNEO_HH_

#include "Lista_Jugadores.hh"
#include "Categorias.hh"

#ifndef NO_DIAGRAM
#include <string>
#include "BinTree.hh"
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
typedef vector< vector<int> > Matriz;
#endif

/** @class Torneo
    @brief Representa a un torneo con ciertos atrivutos y sus operaciones.
*/
class Torneo {

private:

  bool esta_iniciado;

  int cat;

  //Arboles de emparejamientos y resultados
  /**@brief Arbol de participantes al iniciarlo (arbol de emparejamientos)*/
  BinTree<int> part;
  /**@brief Arbol de participantes al finalizarlo (arbol de resultados)*/
  BinTree<int> res;
  /**@brief Arbol de puntuaciones*/
  BinTree<string> punt;

  /**@brief Vector de participantes del torneo*/
  vector<string> participantes;                               //Cada i de los dos vectores tienen
  /**@brief Vector de puntos de cada jugador del torneo*/
  vector<int> puntos_jugador;                                 //que corresponder al mismo jugador.
  
  //Historial de los jugadores
  /**@brief Vector de participantes de la edición anterior del torneo*/
  vector<string> ant_participantes;
  /**@brief Vector de puntos de cada jugador de la edición anterior del torneo*/
  vector<int> ant_puntos_jugador;

  /**@brief Matriz de estadísticas locales de cada jugador*/
  Matriz est_local;

  /** @brief Construye e imprime el arbol de emparejamientos.

      \pre v.size() <= 8, l <= 2
      \post Devuelve el arbol de emparejamientos hecho con los nodos en orden creciente de inscripción y te imprime los emparejamientos.
  */
  static void arbol_emp(BinTree<int> &a, const vector<string> &v, int l, bool &cond);

  /** @brief Resta los puntos de la edición anterior a los jugadores.

      \pre <em>cierto</em>
      \post La clase "Lista Jugadores" tiene los puntos de cada jugador modificado dependiendo de la edición anterior del torneo.
  */
  void act_puntos_viejo_torneo(Lista_Jugadores &ljug);

  /** @brief Construye el arbol de puntuación de los sets conseguidos en cada partido.

      \pre <em>cierto</em>
      -----Las strings han de ser de tipo "1-0", "0-1", "x-y,x-y" ... "x-y,y-x,x-y"... donde x = 6/7, 1 <= y <= 5
      \post Devuelve un arbol de string donde cada string son los sets conseguidos en cada partido, a excepción de los partidos que son "1-0" y "0-1".
  */
  static void arbol_punt(BinTree<string> &a);

  /** @brief Devuelve el ganador dado dos jugadores y unos resultados de un partido.

      \pre 1 <= a y 1 <= b
      \post Expulsa a o b dependiendo de quien ha ganado.
  */
  static int winner(int a, int b, const string &x);

  /** @brief Construye el arbol de resultados tras comprobar quien es el ganador en cada nodo del arbol de emparejamientos fijandose en el arbol de puntuación.

      \pre <em>cierto</em>
      \post Devuelve el arbol de enteros de los emparejamientos una vez modificado con los ganadores de cada partido. 
  */
  static void arbol_res(BinTree<int> &a, const BinTree<int> &part, const BinTree<string> &punt);

  /** @brief Modificadora de la matriz est_local[][6] del parámetro implicito.

      \pre l <= 1
      \post La matriz est_local del parámetro implícito tiene la 6 columna modificada con los niveles donde se han quedado los jugadores.
  */
  void mod_puntos(const BinTree<int> &res, int l);

  /** @brief Modificadora de la matriz est_local con las estadisticas de dos jugadores.

      \pre j1 >= 1, j2 >= 1 y string tipo: "1-0", "0-1", "x-y,x-y" ... "x-y,y-x,x-y"... donde x = 6/7, 1 <= y <= 5
      \post La matriz queda modificada con las estadisticas de los dos jugadores
  */
  void anadir_est_matriz(int &j1, int &j2, const string &puntos);

  /** @brief Imprime el cuadro de resultados.

      \pre res, punt y part construidos previamente.
      \post Imprime el cuadro de emparejamientos con los dos jugagores de cada partidos con los resultados del partido, imprimiendo desde arriba en preorden.
  */
  void imprimir_res(const BinTree<int> &res, const BinTree<string> &punt, const vector<string> &part);

  /** @brief Imprime los puntos de los jugadores

      \pre <em>cierto</em>
      \post Imprime los puntos de los jugadores en orden de entrada de los jugadores al torneo. Los jugadores con 0 puntos no se imprimen.
  */
  void mod_puntos(const vector<string> &part, const Matriz &est, vector<int> &punt, const Categorias &lcat);

public:

  //Constructora
  
  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un torneo.
      \pre <em>cierto</em>
      \post El resultado es un torneo no inicializado.
  */
  Torneo();

  /** @brief Creadora con la categoría preseleccionada. 

      \pre c >= 0 y t tiene que ser un identificador válido.
      \post El resultado es un torneo inicializado con el identificador y la categoría.
  */
  Torneo(const int &c);

  //Modificadoras

  /** @brief Se inicia el parámetro implícito.

      \pre v tiene que tener los strings en orden de ranking y n = al tamaño del vector v
      \post Se inicia el torneo.
  */
  void inic_torneo(const vector<string> &v);

  /** @brief Se finalizar el parámetro implícito.

      \pre <em>cierto</em>
      \post Se finaliza el torneo.
  */
  void fini_torneo(Lista_Jugadores &ljug, const Categorias &lcat);

  /** @brief Modificadora de los puntos de un jugador en ediciones anteriores al darlo de baja.

      \pre <em>cierto</em>
      \post Si el jugador con nombre p está en el historial del parámetro implícito, se eliminan los puntos.
  */
  void act_puntos_baja_jug(const string &p);

  /** @brief Modificadora de los puntos de todos los jugadores los cuales han estado inscritos previamente en la edición anterior.

      \pre <em>cierto</em>
      \post Se han restado los puntos del historial de los jugadores con historial en el parámetro implícito.
  */
  void act_est_baja_torneo(Lista_Jugadores &ljug);

  //Consultoras

  bool cons_esta_iniciado() const;

  /** @brief Consultora para saber si hay historial o no.
    
      \pre <em>cierto</em>
      \post True si tiene historial, false si no lo tiene.
  */
  bool hay_historial() const;

  /** @brief Consultora de la categoría del torneo.
    
      \pre <em>cierto</em>
      \post El resultado te dice en que categoría está el torneo.
  */
  int cons_categoria() const;

  //Escritura

  void imprimir_puntos() const;
};

#endif