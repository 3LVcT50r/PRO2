/** @file Categorias.hh
    @brief Especificación de la clase Categorias
*/

#ifndef _CATEGORIAS_HH_
#define _CATEGORIAS_HH_

#ifndef NO_DIAGRAM 
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

  /*
  struct Categ
  {
    string nombre;
    vector<int> puntos_niveles;
    int puntos_totales;
  };

  map<int,Categ> lcat;
  */
  
  int numero_categorias;
  vector<string> nom;
  Matriz p_lvl;

public:

  //Constructuras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista de categorías.
      \pre <em>cierto</em>
      \post El resultado son las categorías no inicializadas.
  */ 
  Categorias();

  //Destructora

  /** @brief Destructora por defecto.
  */
  ~Categorias();

  //Modificadora

  /** @brief Modifica los puntos de una categoría.

      \pre 1 <= c <= numero de categorías, p >= 0
      \post El total de puntos de esa categoría ha aumentado p puntos.
  */
  void mod_puntos_categoria(int c, int p);

  //Consultoras

  /** @brief Consultora del nombre de una categoría.

      \pre 1 <= c <= numero de categorías
      \post El resultado es el nombre de la categoría .
  */
  string cons_nombre(int c) const;

  /** @brief Consultora de los puntos por nivel.

      \pre 0 <= k <= tamaño del vector -1.
      \post El resultado son los puntos por nivel.
  */
  int cons_puntos_por_nivel(int c, int k) const;

  /** @brief Consultora de los puntos totales de cada categoría.

      \pre 1 <= c <= numero de categorías.
      \post El resultado son los puntos de cada categoría.
  */
  int cons_puntos_totales_por_cat(int c) const;

  //Lectura y escritura

  /** @brief Operación de lectura y modificadora inicial.

      \pre c >= 0 y k >= 4
      \post El parámetro implícito con todas sus variables ya declaradas.
  */
  void leer(int c, int k);

  /** @brief Escritura de la tabla de nombre y de puntos por niveles de cada categoría.

      \pre <em>cierto</em>
      \post Se expulsa por terminal la tabla de nombres y de puntos por niveles por orden creciente de identificador. 
  */
  void listar_categorias() const;

};

#endif