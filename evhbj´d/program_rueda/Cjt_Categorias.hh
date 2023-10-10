  
 #ifndef CONJ_CAT_HH
 #define CONJ_CAT_HH
  
#include <iostream>
 #include <vector>
using namespace std;

 class Cjt_Categorias {
  
 public:
     //Constructoras
  
     Cjt_Categorias();
  
     //Consultoras
  
     string consultar_categoria(int c) const;
     
     bool existe_categoria(int c) const;
     
     int consultar_puntos(int c, int n) const;
  
     //Lectura y escritura
  
     void escribir() const;
  
     void leer();
  
 private:
     vector<vector<int> > vcat;
     vector<string> nom_cat;
 };
 #endif 
