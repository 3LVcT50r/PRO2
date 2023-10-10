 #include "Cjt_Torneos.hh"
 #include "Cjt_Jugadores.hh"
 #include "Cjt_Categorias.hh"
  
 int main() {
     Cjt_Categorias cc;
     Cjt_Torneos ct;
     Cjt_Jugadores cj;
     cc.leer();
     ct.inicializar();
     cj.inicializar();
     string comando;
     cin >> comando;
     while (comando != "fin") {
         if (comando == "nj" or comando == "nuevo_jugador") {
             string id;
             cin >> id;
             cout << '#' << comando << ' ' << id << endl;
             if (cj.existe_jugador(id)) cout << "error: ya existe un jugador con ese nombre" << endl;
             else cj.anadir_jugador(id);
         }
         else if (comando == "nt" or comando == "nuevo_torneo") {
             string id;
             cin >> id;
             int cat;
             cin >> cat;
             cout << '#' << comando << ' ' << id << ' ' << cat << endl;
             if (not cc.existe_categoria(cat)) cout << "error: la categoria no existe" << endl;
             else if (ct.existe_torneo(id)) cout << "error: ya existe un torneo con ese nombre" << endl;
             else ct.anadir_torneo(id,cat);
             
         }
         
         else if (comando == "bj" or comando == "baja_jugador") {
             string p;
             cin >> p;
             cout << '#' << comando << ' ' << p << endl;
             if (not cj.existe_jugador(p)) cout << "error: el jugador no existe" << endl;
             else {
                 cj.baja_jugador(p);
                 ct.eliminar_jugador(p);
             }
         }
         else if (comando == "bt" or comando == "baja_torneo") {
             string id;
             cin >> id;
             cout << '#' << comando << ' ' << id << endl;
             if (not ct.existe_torneo(id)) cout << "error: el torneo no existe" << endl;
             else ct.baja_torneo(id,cj);
             
         }
         else if (comando == "it" or comando == "iniciar_torneo") {
             string id;
             cin >> id;
             cout << '#' << comando << ' ' << id << endl;
             ct.iniciar_torneo(id,cj);
             }
         else if (comando == "ft" or comando == "finalizar_torneo") {
             string id;
             cin >> id;
             cout << '#' << comando << ' ' << id << endl;
             ct.finalizar_torneo(id,cj,cc);
         }
        
         else if (comando == "lr" or comando == "listar_ranking") {
             cout << '#' << comando << endl;
             cj.escribir_ranking();
         }
         else if (comando == "lj" or comando == "listar_jugadores") {
             cout << '#' << comando << endl;
             cj.escribir_jugadores();
         }
         else if (comando == "cj" or comando == "consultar_jugador") {
             string id;
             cin >> id;
             cout << '#' << comando << ' ' << id << endl;;
             if (not cj.existe_jugador(id)) cout << "error: el jugador no existe" << endl;
             else cj.escribir_jugador(id);
              
             }
         else if (comando == "lt" or comando == "listar_torneos") {
             cout << '#' << comando << endl;
             ct.escribir_torneos(cc);
         }
         else if (comando == "lc" or comando == "listar_categorias") {
             cout << '#' << comando << endl;
             cc.escribir();
         }
         cin >> comando;
     }
      
 } 
