/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{

  Lavadora l;
  Cubeta c;

  /* 
  cout << " Lavadora: " << endl;
  l.escribir():
  cout << " Cubeta: " << endl;
  c.escribir();
   */

  int option;
  cin >> option;

  while (option != -8) {

    if (option == -1) {
      int peso_max;
      cin >> peso_max;

      bool l_color = readbool();

      l.inicializar(peso_max, l_color);
    }

    else if (option == -2) {
      int peso;
      cin >> peso;

      bool color = readbool();

      Prenda p (peso, color);
      l.anadir_prenda(p);
    }

    else if (option == -3) {
      int peso;
      cin >> peso;

      bool color = readbool();

      Prenda p (peso, color);
      c.anadir_prenda(p);
    }

    else if (option == -4) {
      c.completar_lavadora(l);
    }

    else if (option == -5) {
      l.lavado();
    }

    else if (option == -6) {
      cout << " Cubeta: " << endl;
      c.escribir();
    }

    else if (option == -7) {
      cout << " Lavadora: " << endl;
      l.escribir();
    }


    cin >> option;
  }
}
