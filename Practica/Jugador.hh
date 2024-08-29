/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef _JUGADOR_HH_
#define _JUGADOR_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Jugador
    @brief Representa a un jugador con ciertos atrivutos y sus operaciones.
*/
class Jugador {

private:
  /**@brief Posición del ranking del jugador*/
  int ranking;
  /**@brief Puntos conseguidos del jugador*/
  int puntos;
  /**@brief Total de torneos jugados del jugador*/
  int torn_jugados;
  /**@brief Numero de partidos ganas*/
  int wm;
  /**@brief Numero de partidos perdidos*/
  int lm;
  /**@brief Numero de juegos ganados*/
  int wg; 
  /**@brief Numero de juegos perdidos*/
  int lg; 
  /**@brief Numero de sets ganados*/
  int ws; 
  /**@brief Numero de sets peridos*/
  int ls; 

public:

  //Constructuras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un jugador.
      \pre <em>cierto</em>
      \post El resultado es un jugador no inicializado
  */ 
  Jugador();
  
  //Modificadoras

  /** @brief Modificadora del ranking del parámetro implícito.
    
      \pre r un entero cualquiera.
      \post Modifica el ranking del parámetro implícito.
  */
  void mod_ranking(const int &r);

  /** @brief Modificadora de los puntos del parámetro implícito.
    
      \pre pt un entero cualquiera.
      \post Modifica el numero de puntos del parámetro implícito sumandolos.
  */
  void mod_puntos(const int &pt);

  /** @brief Modificadora de los torneos jugados.
    
      \pre tj un entero cualquiera.
      \post Modifica el numero de torneo jugados del parámetro implicito.
  */
  void mod_torn_jugados(const int &tj);

  /** @brief Modificadora de los partidos ganados.
    
      \pre pg un entero cualquiera.
      \post Modifica el numero de partidos ganados del parámetro implicito sumandolos.
  */
  void mod_wm(const int &pg);

  /** @brief Modificadora de los partidos perdidos.
    
      \pre pp un entero cualquiera.
      \post Modifica el numero de partidos perdidos del parámetro implicito.
  */
  void mod_lm(const int &pp);

  /** @brief Modificadora de los juegos ganados.
    
      \pre pg un entero cualquiera.
      \post Modifica el numero de juegos ganados del parámetro implicito.
  */
  void mod_wg(const int &jg);

  /** @brief Modificadora de los juegos perdidos.
    
      \pre pg un entero cualquiera.
      \post Modifica el numero de juegos perdidos del parámetro implicito.
  */
  void mod_lg(const int &jp);

  /** @brief Modificadora de los sets ganados.
    
      \pre pg >un entero cualquiera.
      \post Modifica el numero de sets ganados del parámetro implicito.
  */
  void mod_ws(const int &sg);

  /** @brief Modificadora de los sets perdidos.
    
      \pre pg un entero cualquiera.
      \post Modifica el numero de sets perdidos del parámetro implicito.
  */
  void mod_ls(const int &sp);

  //Consultoras

  /** @brief Consultora del ranking del parámetro implícito.
    
      \pre <em>cierto</em>
      \post El resultado es la posición en el ranking del parámetro implícito.
  */
  int cons_ranking() const;

  /** @brief Consultora de los puntos del parámetro implícito.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de puntos del parámetro implícito.
  */
  int cons_puntos() const;

  /** @brief Consultora de los torneos jugados.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de torneos jugados del parámetro implícito.
  */
  int cons_torn_jugados() const;

  /** @brief Consultora de los partidos ganados.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de partidos ganados del parámetro implícito.
  */
  int cons_wm() const;

  /** @brief Consultora de los partidos perdidos.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de partidos perdidos del parámetro implícito.
  */
  int cons_lm() const;

  /** @brief Consultora de los juegos ganados.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de juegos ganados del parámetro implícito.
  */
  int cons_wg() const;

  /** @brief Consultora de los juegos perdidos.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de juegos perdidos del parámetro implícito.
  */
  int cons_lg() const;

  /** @brief Consultora de los sets ganados.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de sets ganados del parámetro implícito.
  */
  int cons_ws() const;

  /** @brief Consultora de los sets perdidos.
    
      \pre <em>cierto</em>
      \post El resultado es el numero de sets perdidos del parámetro implícito.
  */
  int cons_ls() const;
};

#endif