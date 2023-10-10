#include "Cjt_Jugadores.hh"
#include <algorithm>

void swap_pair(pair<string, int> &a, pair<string, int> &b) {
    pair<string, int> c = a;
     a = b;
     b = c;
}

void enviar_ultimo(vector<pair<string, int> > &ranking, int i){
    int n = ranking.size();
    for (int j = i; j < n-1; ++j) {
        swap_pair(ranking[j],ranking[j+1]);
    }
}


Cjt_Jugadores::Cjt_Jugadores(){
}

void Cjt_Jugadores::modificar_puntos(string n, int puntos){
    jugadores[n].modificar_puntos(puntos);
    int pos = jugadores[n].consultar_posicion();
    ranking[pos-1].second += puntos;
}

void Cjt_Jugadores::modificar_torneos(string n,int t){
    jugadores[n].modificar_torneos_disputados(t);
}

void Cjt_Jugadores::modificar_pg(string n, int pg){
    jugadores[n].modificar_pg(pg);
}

void Cjt_Jugadores::modificar_pp(string n, int pp){
    jugadores[n].modificar_pp(pp);
}

void Cjt_Jugadores::modificar_sets(string n, int sg, int sp){
    jugadores[n].modificar_sets(sg,sp);
}

void Cjt_Jugadores::modificar_juegos(string n, int jg, int jp){
    jugadores[n].modificar_juegos(jg,jp);
}

//añadir jugador
void Cjt_Jugadores::anadir_jugador(string n){
    ranking.push_back(make_pair(n,0)); //añadir en ranking
    Jugador nj(ranking.size());
    jugadores.insert(make_pair(n,nj));//añadir en el map
    cout << jugadores.size() << endl;
}


//baja jugador
void Cjt_Jugadores::baja_jugador(string n){
    int pos_elim;
    pos_elim = jugadores[n].consultar_posicion();
    jugadores.erase(jugadores.find(n));//eliminar en el map
    //eliminar en el vector y actualizar rk;
    int x = ranking.size();
    for (int j = pos_elim-1; j < x-1; ++j) {
        swap_pair(ranking[j],ranking[j+1]);
        jugadores[ranking[j].first].modificar_posicion(j+1);
    }
    ranking.pop_back();
    cout << ranking.size() << endl;
    
}

//existe jugador

bool Cjt_Jugadores::existe_jugador(string n) const{
    map<string, Jugador>::const_iterator it = jugadores.find(n);
    if (it == jugadores.end()) return false;
    else return true;
    
}

string Cjt_Jugadores::consultar_jugador(int pos) const{
    return ranking[pos-1].first;
    
}

//escribir por nombre

void Cjt_Jugadores::escribir_jugador(string n) {
    cout << n;
    jugadores[n].escribir();
}


void Cjt_Jugadores::escribir_jugadores(){
    cout << jugadores.size() << endl;
    for (map<string, Jugador>::const_iterator it = jugadores.begin(); it != jugadores.end(); ++it) {
        cout << it->first;
        it->second.escribir();
    }
}

//escibir ranking

void Cjt_Jugadores::escribir_ranking(){
    int n = ranking.size();
    for (int i = 0; i < n; ++i) {
        cout << i+1 << ' ' << ranking[i].first << ' ' << ranking[i].second << endl;
    }
}

//inicializar

void Cjt_Jugadores::inicializar(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string j;
        cin >> j;
        ranking.push_back(make_pair(j,0)); //añadir en ranking
        Jugador nj(i+1);
        jugadores.insert(make_pair(j,nj));//añadir en el map
    }
}

bool comp(pair<string,int> a, pair<string,int> b){
    return (a.second > b.second);
}

void Cjt_Jugadores::ordenar_ranking(){
    stable_sort(ranking.begin(),ranking.end(),comp);
    int n = ranking.size();
    for (int i = 0; i < n; ++i){
        jugadores[ranking[i].first].modificar_posicion(i+1);
    }
}




