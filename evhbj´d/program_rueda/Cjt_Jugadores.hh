  
 #ifndef CONJ_JUG_HH
 #define CONJ_JUG_HH
  
 #include "Jugador.hh"
  
 #ifndef NO_DIAGRAM
 #include <map>
#include <vector>
  
 #endif
  
 class Cjt_Jugadores {
  
  
 public:
   //Constructoras
  
   Cjt_Jugadores();
  
   //Modificadoras
  
   void anadir_jugador(string n);
  
   void baja_jugador(string n);
   
   void modificar_puntos(string n,int puntos);
   
   void modificar_torneos(string n,int t);
   
   void modificar_pg(string n,int pg);
   
   void modificar_pp(string n,int pp);
   
   void modificar_sets(string n,int sg,int sp);
   
   void modificar_juegos(string n, int jg, int jp);
   
   void ordenar_ranking();
  
   //Consultoras
  
   bool existe_jugador(string n) const;
   
   string consultar_jugador(int pos) const;
  
   //Lectura y escritura
   
   void escribir_jugador(string n);
   
   void escribir_jugadores();
  
   void escribir_ranking();
  
   void inicializar();
  
 private:
   vector<pair<string, int> > ranking;
   map<string, Jugador> jugadores;
  
 };
  
  
 #endif 
