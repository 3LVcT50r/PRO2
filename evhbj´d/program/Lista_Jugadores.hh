/** @file Lista_Jugadores.hh
    @brief Especificación de la clase Lista_Jugadores
*/

#ifndef _LIST_JUGADORES_HH_
#define _LIST_JUGADORES_HH_

#include "Jugador.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <map>
#include <utility>
#include <vector>
using namespace std;
#endif

/** @class Lista_Jugadores
    @brief Representa la lista de jugadores o ranking con ciertos atrivutos y sus operaciones.
*/
class Lista_Jugadores {

private:

  map<string,Jugador> ljug;

  vector<pair<string,int>> v;

  int numero_jugadores;

public:

  //Constructuras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista de jugadores.
      \pre <em>cierto</em>
      \post El resultado es una lista de jugadores no inicializada.
  */ 
  Lista_Jugadores();

  //Destructora

  /** @brief Destructora por defecto.
  */
  ~Lista_Jugadores();

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

  //Consultoras

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

  map<string,Jugador> mapa();

  //Lectura y escritura

  /** @brief Operación de lectura.

      \pre j >= 0.
      \post El parámetro implícito con todos sus jugadores declarados.
  */
  void leer(int j);

  /** @brief Escritura para listar el ranking. 

      \pre <em>cert</em>
      \post Se expulsa por terminal el listamiento del ranking en orden.
  */
  void listar_ranking() const;

  /** @brief Escritura para listar los jugadores. 

      \pre <em>cert</em>
      \post Se expulsa por terminal el listamiento de los jugadores en orden.
  */
  void listar_jugadores() const;

  /** @brief Escritura para listar a un jugador. 

      \pre <em>cert</em>
      \post Se expulsa por terminal el listamiento del jugador.
  */
  void listar_jugador(const string &p) const;

  /** @brief te devuelve una copia de la lista de jugadores en el orden del ranking. 

      \pre <em>cert</em>
      \post Se un vector de pares de string y enteros ordenados por el entero.
  */
  vector<pair<string,int>> copia_vector_ranking();
};

#endif