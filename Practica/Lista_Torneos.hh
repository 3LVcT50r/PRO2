/** @file Lista_Torneos.hh
    @brief Especificación de la clase Lista_Torneos
*/

#ifndef _LIST_TORNEOS_HH_
#define _LIST_TORNEOS_HH_

#include "Torneo.hh"
#include "Categorias.hh"
#include "Lista_Jugadores.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#endif

/** @class Lista_Torneos
    @brief Representa la lista de torneos o circuito con ciertos atrivutos y sus operaciones.
*/
class Lista_Torneos {

private:

  /**@brief Mapa de los torneos
     Ordenados alfabeticamente por el nombre de los torneos*/
  map<string,Torneo> ltorn;
  /**@brief Numero total de los torneos*/
  int numero_torneos;

public:

  //Constructuras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista de torneos.
      \pre <em>cierto</em>
      \post El resultado es una lista de torneos no inicializada.
  */ 
  Lista_Torneos();

  //Modificadoras

  /** @brief Añade un nuevo torneo en el circuito.
      
      \pre t tiene que estar contenido dentro del mapa del parámetro implícito.
      \post La lista de torneos tiene ahora un torneo más con el identificador t y la categoría c.
  */
  void nuevo_torneo(const string &t, const int &c);

  /** @brief Da de baja un torneo del circuito y se eliminan los puntos de ese torneo.
      
      \pre t tiene que estar contenido dentro del mapa del parámetro implícito.
      \post La lista de torneos tiene ahora un torneo menos y con los puntos de ese torneo eliminados.
  */
  void baja_torneo(const string &t, Lista_Jugadores &ljug);

  /** @brief Da la orden de iniciar el torneo torneo con identificador t.
      
      \pre t tiene que estar contenido dentro del mapa del parámetro implícito y 0 <= n <= total de Lista_Jugadores.
      \post Se inscribe los participantes del torneo, se imprime los emparejamientos y se inicia el torneo.
  */
  void iniciar_torneo(const string &t, const int &n, Lista_Jugadores &ljug);

  /** @brief Da la orden de finalizar el torneo torneo con identificador t
      
      \pre t tiene que estar contenido dentro del mapa del parámetro implícito.
      \post Se imprime los resultados de los emparejamientos y los puntos optenidos por cada jugador, se actualiza los puntos de los jugadores y se finaliza el torneo.
  */
  void finalizar_torneo(const string &t, Lista_Jugadores &ljug, const Categorias &lcat);

  /** @brief Actualiza los puntos de la edición anterior del jugador mencionado.
      
      \pre <em>cierto</em>
      \post Elimina los puntos de ediciones anteriores de todos los torneos en los que haya estado el jugador con nombre p.
  */
  void act_baja_jugador(const string &p);

  //Consultoras

  /** @brief Consultora de indentificacion del torneo. 
  
      \pre t tiene que ser una identificación correcta.
      \post 1 si existe un torneo con el mismo identificador, 0 si no existe.
  */
  bool identificador_torneo(const string &t) const;

  /** @brief Consultora del numero de torneos. 
  
      \pre <em>cierto</em>
      \post El resultado es el número de torneos que tiene el parámetro implícito.
  */
  int num_torneos() const;

  //Lectura y escritura

  /** @brief Operación de lectura.

      \pre n >= 0.
      \post El parámetro implícito con todos sus torneos declarados.
  */
  void leer(const int &n); 

  /** @brief Escritura para listar los torneos. 

      \pre <em>cierto</em>
      \post Se expulsa por terminal el listamiento de los torneos en orden.
  */
  void listar_torneos(const Categorias &cat) const;
};

#endif