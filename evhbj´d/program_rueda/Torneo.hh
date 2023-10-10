 #ifndef TORNEO_HH
 #define TORNEO_HH
  
 #include "Cjt_Jugadores.hh"
#include "Cjt_Categorias.hh"
 #include "Jugador.hh"
  
 #ifndef NO_DIAGRAM
 #include "BinTree.hh"
 #endif
  
 class Torneo {
  
     
 public:
     //Constructoras
  
     Torneo();
     Torneo(int cat);
  
     //Modificadoras
  
     void iniciar(Cjt_Jugadores& cj);
  
     void finalizar(Cjt_Jugadores& cj,Cjt_Categorias& cc);
     
     void eliminar_jugador(string n);
     
     void restar_puntos(Cjt_Jugadores &cj);
  
     //Consultoras
  
     int consultar_categoria() const;
  
     bool esta_inicializado() const;
  
     //Lectura y escritura
  

  
 private:
     int c;
     bool inicializado;
     vector<pair<string,int> > ranking_local;
     vector<pair<string,int> > historial;
     BinTree<int> cuadro_emparejamientos;
     
        
 };
 #endif 
