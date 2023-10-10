/** @file Categorias.hh
    @brief Especificación de la clase Categorias
*/

#ifndef _CATEGORIAS_HH_
#define _CATEGORIAS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef vector< vector<int> > Matriz;
#endif

/** @class Categorias
    @brief Representa las categorías del circuito con sus atrivutos y sus operaciones.
*/
class Categorias {

private:

  /**@brief Numero de categorías*/
  int numero_categorias;
  /**@brief Vector de los nombres de las categorías
     Ordenado por el numero de la categoría*/
  vector<string> nom;
  /**@brief Matriz de los puntos por cada categoría
     Ordenado por filas crecientemente por numero de la categoría y las columnas decrecientemente por el nivel*/
  Matriz p_lvl;

public:

  //Constructuras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista de categorías.
      \pre <em>cierto</em>
      \post El resultado son las categorías no inicializadas.
  */ 
  Categorias();

  //Consultoras

  /** @brief Consultora del nombre de una categoría.

      \pre 1 <= c <= numero de categorías
      \post El resultado es el nombre de la categoría .
  */
  string cons_nombre(const int &c) const;

  /** @brief Consultora de los puntos por nivel.

      \pre 0 <= k <= tamaño del vector -1.
      \post El resultado son los puntos por nivel.
  */
  int cons_puntos_por_nivel(const int &c, const int &k) const;

  //Lectura y escritura

  /** @brief Operación de lectura y modificadora inicial.

      \pre c >= 0 y k >= 4
      \post El parámetro implícito con todas sus variables ya declaradas.
  */
  void leer(const int &c, const int &k);

  /** @brief Escritura de la tabla de nombre y de puntos por niveles de cada categoría.

      \pre <em>cierto</em>
      \post Se expulsa por terminal la tabla de nombres y de puntos por niveles por orden creciente de identificador. 
  */
  void listar_categorias() const;

};

#endif