  
 #ifndef JUGADOR_HH
 #define JUGADOR_HH
  
 #ifndef NO_DIAGRAM
 #include <iostream>
 #endif
  
 using namespace std;
  
 class Jugador {
     
 public:
     //Constructoras
  
     Jugador();

     Jugador(int pos);
     
     //Modificadoras
  
     void modificar_posicion(int pos);
  
     void modificar_puntos(int p);
  
     void modificar_torneos_disputados(int td);
     
     void modificar_pg(int pg);
     
     void modificar_pp(int pp);
  
     void modificar_sets(int sg,int sp);
  
     void modificar_juegos(int jg,int jp);
  
     //Consultoras
  
  
     int consultar_posicion() const;
  
     int consultar_puntos() const;
  
     //Lectura y escritura
     
     void escribir() const;
  
 private:
     //no hace falta nombre porque ya esta en el map
     int posicion;
     int puntos;
     int torneos_disputados;
     int partidos_ganados;
     int partidos_perdidos;
     int sets_ganados;
     int sets_perdidos;
     int juegos_ganados;
     int juegos_perdidos;
  
 };
 #endif 
