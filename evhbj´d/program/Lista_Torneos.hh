/** @file Lista_Torneos.hh
    @brief Especificación de la clase Lista_Torneos
*/

#ifndef _LIST_TORNEOS_HH_
#define _LIST_TORNEOS_HH_

#include "Torneo.hh"
#include "Categorias.hh"
#include "Lista_Jugadores.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <map>
#include <vector>
#endif

/** @class Lista_Torneos
    @brief Representa la lista de torneos o circuito con ciertos atrivutos y sus operaciones.
*/
class Lista_Torneos {

private:

  map<string,Torneo> ltorn;
  int numero_torneos;

public:

  //Constructuras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista de torneos.
      \pre <em>cierto</em>
      \post El resultado es una lista de torneos no inicializada.
  */ 
  Lista_Torneos();

  //Destructora

  /** @brief Destructora por defecto.
  */
  ~Lista_Torneos();

  //Modificadoras

  /** @brief Añade un nuevo torneo en el circuito.
      
      \pre t tiene que ser un identificador correcta.
      \post La lista de torneos tiene ahora un torneo más con el identificador t y la categoría c.
  */
  void nuevo_torneo(const string &t, int c);

  /** @brief Da de baja un torneo del circuito y se eliminan los puntos de ese torneo.
      
      \pre t tiene que ser un identificador válido.
      \post La lista de torneos tiene ahora un torneo menos y con los puntos de ese torneo eliminados.
  */
  void baja_torneo(const string &t);

  /** @brief Inicia un torneo.
      
      \pre t tiene que ser un identificador válido y 0 <= n <= total de Lista_Jugadores.
      \post Se inscribe los participantes del torneo, se imprime los emparejamientos y se inicia el torneo.
  */
  void iniciar_torneo(const string &t, int n, Lista_Jugadores &ljug);

  /** @brief Finaliza un torneo.
      
      \pre t tiene que ser un identificador válido.
      \post Se imprime los resultados de los emparejamientos, se actualiza los puntos totales por categoría y se finaliza el torneo.
  */
  void finalizar_torneo();

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

  /** @brief Te retorna un torneo individual a partir de el identificador. 
  
      \pre t es un identificador válido.
      \post El resultado es un torneo completo.
  */
  Torneo consultar_torneo(const string &t) const;

  //Lectura y escritura

  /** @brief Operación de lectura.

      \pre n >= 0.
      \post El parámetro implícito con todos sus torneos declarados.
  */
  void leer(int n); 

  /** @brief Escritura para listar los torneos. 

      \pre <em>cert</em>
      \post Se expulsa por terminal el listamiento de los torneos en orden.
  */
  void listar_torneos(const Categorias &cat) const;
};

#endif