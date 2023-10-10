#include "Cjt_Torneos.hh"

Cjt_Torneos::Cjt_Torneos(){
    
}


void Cjt_Torneos::anadir_torneo(string id, int c){
    Torneo nt(c);
    torneos.insert(make_pair(id,nt));
    cout << torneos.size() << endl;
    
}

void Cjt_Torneos::iniciar_torneo(string id, Cjt_Jugadores &cj){
    torneos[id].iniciar(cj);
}


void Cjt_Torneos::baja_torneo(string id,Cjt_Jugadores &cj){
    torneos[id].restar_puntos(cj);
    cj.ordenar_ranking();
    torneos.erase(torneos.find(id));
    cout << torneos.size() << endl;
}

void Cjt_Torneos::eliminar_jugador(string id){
    for (map<string, Torneo>::const_iterator it = torneos.begin(); it != torneos.end(); ++it) {
        string x = it->first;
        torneos[x].eliminar_jugador(id);
    }
    
}

bool Cjt_Torneos::existe_torneo(string n) const{
    map<string, Torneo>::const_iterator it = torneos.find(n);
    if (it == torneos.end()) return false;
    else return true;
}

void Cjt_Torneos::escribir_torneos(Cjt_Categorias &cc){
    cout << torneos.size() << endl;
    for (map<string, Torneo>::const_iterator it = torneos.begin(); it != torneos.end(); ++it) {
        cout << it->first << ' ' << cc.consultar_categoria((it->second).consultar_categoria()) << endl;
    }
}

void Cjt_Torneos::finalizar_torneo(string id,Cjt_Jugadores& cj,Cjt_Categorias& cc){
    torneos[id].finalizar(cj,cc);
}


void Cjt_Torneos::inicializar(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string id;
        cin >> id;
        int c;
        cin >> c;
        Torneo nt(c);
        torneos.insert(make_pair(id,nt));
        
    }
}
