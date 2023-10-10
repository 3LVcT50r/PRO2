  
 #ifndef CONJ_TOR_HH
 #define CONJ_TOR_HH
  
 #include "Torneo.hh"
 #include "Cjt_Jugadores.hh"
#include <map>
 class Cjt_Torneos {
  
 public:
     //Constructoras
  
     Cjt_Torneos();
  
     //Modificadoras
     
     void iniciar_torneo(string id, Cjt_Jugadores &cj);
     
     void finalizar_torneo(string id,Cjt_Jugadores &cj,Cjt_Categorias &cc);
  
     void anadir_torneo(string id, int cat);
  
     void baja_torneo(string id,Cjt_Jugadores &cj);
     
     void eliminar_jugador(string id);
  
     //Consultoras
  
     bool existe_torneo(string nombre) const;
  
     //Lectura y escritura
  
     void escribir_torneos(Cjt_Categorias &cc);
  
     void inicializar();
  
 private:
  
   map<string, Torneo> torneos;
  
 };
 #endif 
