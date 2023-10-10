/** @file Torneo.hh
    @brief Especificacion de la clase Torneo
*/

#ifndef _TORNEO_HH_
#define _TORNEO_HH_

#include "Jugador.hh"
#include "Lista_Jugadores.hh"

#ifndef NO_DIAGRAM
#include <string>
#include "BinTree.hh"
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
#endif

/** @class Torneo
    @brief Representa a un torneo con ciertos atrivutos y sus operaciones.
*/
class Torneo {

private:

  bool esta_iniciado;
  vector<Jugador> participantes;
  int cat;
  BinTree<int> arbol_emparejamientos;
  int puntos_totales;

  static void arbol(BinTree<int> &a, const vector<string> v, int l, bool cond) {

  int sizev = v.size();
  int z = pow(2, l - 1);
  int pote = pow(2, l - 2);

  if ((sizev) < (z + 1 - a.value())) {
    if (a.value() <= pote/2) cout << a.value() << '.' << v[a.value() - 1];
    else cout << ' ' << a.value() << '.' << v[a.value() - 1];
  } 
  else {
    BinTree<int> b(a.value());
    if (cond) cout << ' ';
    cond = false;
    cout << '(';
    arbol(b, v, l+1, cond);
    cond = true;
    BinTree<int> c(z + 1 - a.value());
    arbol(c, v, l+1, cond);
    cout << ')';
    a = BinTree<int> (a.value(), b, c);
  }
}

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
  Torneo(int c);

  //Destructura

  /** @brief Destructora por defecto.
  */
  ~Torneo();

  //Modificadoras

  /** @brief Modificadora para el estado del torneo.

      \pre <em>cierto</em>
      \post 1 si el torneo esta iniciado, 0 si no lo está.
  */
  void mod_estado_torneo(bool estado);

  /** @brief Modificadora para los puntos totales del torneo.

      \pre p >= 0
      \post Modifica los puntos totales que se han ganado en un torneo.
  */
  void mod_puntos_totales(int p);

  /** @brief Se inicia un torneo.

      \pre v tiene que tener los strings en orden de ranking
      \post Se inicia el torneo.
  */
  void ini_torneo(const vector<string> &v);

  //Consultoras

  /** @brief Consultora del estado del torneo.
    
      \pre <em>cierto</em>
      \post 1 si el torneo esta iniciado, 0 si no lo está.
  */
  bool cons_estado_torneo() const;

  /** @brief Consultora de los puntos totales del torneo.
    
      \pre <em>cierto</em>
      \post El resultado son los puntos totales que se han ganado en un torneo.
  */
  int cons_puntos_totales() const;

  /** @brief Consultora de la categoría del torneo.
    
      \pre <em>cierto</em>
      \post El resultado te dice en que categoría está el torneo.
  */
  int cons_categoria() const;
};

#endif