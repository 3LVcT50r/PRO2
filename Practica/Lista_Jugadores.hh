/** @file Lista_Jugadores.hh
    @brief Especificación de la clase Lista_Jugadores
*/

#ifndef _LIST_JUGADORES_HH_
#define _LIST_JUGADORES_HH_

#include "Jugador.hh"

#ifndef NO_DIAGRAM 
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector< vector<int> > Matriz;
#endif

/** @class Lista_Jugadores
    @brief Representa la lista de jugadores o ranking con ciertos atrivutos y sus operaciones.
*/
class Lista_Jugadores {

private:

  /**@brief Represanta un jugador dentro del vector ranking*/
  struct Ranking
  {
    /**@brief Nombre del jugador*/
    string nombre;
    /**@brief Numero de puntos del jugador*/
    int punti;
    /**@brief Numero del ranking*/
    int ranki;
  };

  /**@brief Mapa de los jugadores
     Ordenada alfabeticamente por nombre de los jugadores*/
  map<string,Jugador> ljug;
  /**@brief Vector de ranking de los jugadores
     Ordenada decrecientemente por numero de puntos*/
  vector<Ranking> ranking;
  /**@brief Numero de jugadores totales*/
  int numero_jugadores;

  /** @brief Función de comparación. 

      Función auxiliar para la funcion sort()
      \pre j1, j2 son Estructuras del vector ranking;
      \post True puntos de j1 > punts de j2 o si j2 == j1, ranking anterior de j1 < ranking anterior de j2.
  */
  static bool comp(const Ranking &j1, const Ranking &j2);

public:

  //Constructuras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista de jugadores.
      \pre <em>cierto</em>
      \post El resultado es una lista de jugadores no inicializada.
  */ 
  Lista_Jugadores();

  //Modificadoras

  /** @brief Modifica la lista jugadores para añadir uno nuevo. 

      \pre El objeto Jug tiene que tener un p válido.
      \post El resultado es una lista de jugadores con el jugador nuevo añadido
  */ 
  void nuevo_jugador(const string &p);

  /** @brief Modifica la lista jugadores para eliminar uno. 

      \pre El objeto jugador tiene que tener un p válido.
      \post El resultado tiene que ser una lista de jugadores sin el jugador dado de baja anteriormente.
  */ 
  void baja_jugador(const string &p);

  /** @brief Modifica los puntos y, en consequencia, el ranking de un jugador. 

      \pre part tiene que estar como key-data en el map ljug y punt puede ser cualquier entero.
      \post El jugador nombrado tendra los puntos modificados.
  */
  void act_punt_jug(const string &part, const int &punt);

  /** @brief Modifica las estadisticas del conjunto de jugadores que hay en el vector v. 

      \pre est tiene que tener 7 columnas y todos los strings de v tiene que estar en el map ljug.
      \post Los jugadores con los strings de v tendran las nuevas estadisticas de la matriz est y los puntos del vector puntos.
  */
  void mod_estadisticas(const vector<string> &v, const Matriz &est, const vector<int> &puntos);

  /** @brief Ordena los parámetros implicitos como el vector ranking y modifica los rankings de los jugadores del mapa del parámetro implicito.

      \pre <em>cierto</em>
      \post El vector ranking queda ordenado de forma decreciente de puntos con desempates dependiendo de la posición anterior del ranking.
  */
  void ordenar();

  //Consultoras

  /** @brief Consultora el nombre de un jugador dado un ranking. 

      \pre 1 <= r <= numero de jugadores
      \post Una string que es el nombre del jugador.
  */ 
  string cons_nombre_jugador(const int &r) const;

  /** @brief Consultora de numero de jugadores del circuito. 

      \pre <em>cierto</em>
      \post Un entero positivo con el numero de jugadores del parámetro implícito.
  */ 
  int num_jugadores() const;

  /** @brief Consultora de si existe un jugador con el mismo identificador. 

      \pre p tiene que ser un identificador válido.
      \post 1 si existe, 0 si no existe.
  */ 
  bool identificador_jugador(const string &ide) const;

  //Lectura y escritura

  /** @brief Operación de lectura.

      \pre j >= 0.
      \post El parámetro implícito con todos sus jugadores declarados.
  */
  void leer(const int &j);

  /** @brief Escritura para listar el ranking. 

      \pre <em>cierto</em>
      \post Se expulsa por terminal el listamiento del ranking en orden.
  */
  void listar_ranking() const;

  /** @brief Escritura para listar los jugadores. 

      \pre <em>cierto</em>
      \post Se expulsa por terminal el listamiento de los jugadores en orden.
  */
  void listar_jugadores() const;

  /** @brief Escritura para listar a un jugador. 

      \pre <em>cierto</em>
      \post Se expulsa por terminal el listamiento del jugador.
  */
  void consultar_jugador(const string &p) const;
};

#endif