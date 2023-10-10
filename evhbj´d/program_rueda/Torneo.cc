#include "Torneo.hh"
#include <cmath>

struct partido{
        int ganador;
        int primero;
        int segundo;
        string resultado;
        }; 

Torneo::Torneo(){}

Torneo::Torneo(int cat){
    c = cat;
    
}

int Torneo::consultar_categoria() const{
    return c;

}

bool Torneo::esta_inicializado() const{
    return inicializado;

}

BinTree<int> crear_arbol(int arrel, int prof, int prof_max, int x) {
    
    if (prof > prof_max) {
        BinTree<int> vacio;
        return vacio;
    }
    
    else if (prof == prof_max -1 and arrel <= x) {
        BinTree<int> a(arrel);
        return a;
    }
    
    else  {
        BinTree<int> l = crear_arbol(arrel,prof+1,prof_max,x);
        BinTree<int> r = crear_arbol(pow(2,prof) +1 - arrel,prof + 1,prof_max,x);
        BinTree<int> t (arrel,l,r);
        return t;
    }
}

BinTree<string> crear_resultados(){
    string x;
    cin >> x;
    if (x == "0"){
        BinTree<string> vacio;
        return vacio;
    }
    else {
        BinTree<string> l = crear_resultados();
        BinTree<string> r = crear_resultados();
        BinTree<string> p (x,l,r);
        return p;
    }
    
}

bool gana_izquierda(string resultado,Cjt_Jugadores &cj,vector<pair<string,int> > &ranking_local,int j1, int j2) {
    if (resultado.size() == 3) {
        return resultado[0] > resultado[2];
    }
    
    if (resultado.size() == 7) {
        int ganados = resultado[0] - '0' + resultado[4] - '0';
        int perdidos = resultado[2] - '0' + resultado[6] - '0';
        cj.modificar_juegos(ranking_local[j1-1].first,ganados,perdidos);
        cj.modificar_juegos(ranking_local[j2-1].first,perdidos,ganados);
        if(resultado[0] > resultado[2]){
        cj.modificar_sets(ranking_local[j1-1].first,2,0);
        cj.modificar_sets(ranking_local[j2-1].first,0,2);
        }
        else {
        cj.modificar_sets(ranking_local[j1-1].first,0,2);
        cj.modificar_sets(ranking_local[j2-1].first,2,0);
        }
        return resultado[0] > resultado[2];
    }
    
    else{
        //se puede mejorar eficiencia (No acceder tanto al vector)
        int ganados = resultado[0] + resultado[4]+resultado[8] -3*('0');
        int perdidos = resultado[2]+resultado[6]+resultado[10] -3*('0');
        cj.modificar_juegos(ranking_local[j1-1].first,ganados,perdidos);
        cj.modificar_juegos(ranking_local[j2-1].first,perdidos,ganados);
        if(resultado[8] > resultado[10]){
        cj.modificar_sets(ranking_local[j1-1].first,2,1);
        cj.modificar_sets(ranking_local[j2-1].first,1,2);
        }
        else {
        cj.modificar_sets(ranking_local[j1-1].first,1,2);
        cj.modificar_sets(ranking_local[j2-1].first,2,1);
        }
        return resultado[8] > resultado[10];
    }
    
    
}

BinTree<partido> arbol_final(BinTree<int> a, BinTree<string> b,Cjt_Jugadores &cj,vector<pair<string,int> > &ranking_local,int prof,int cat,Cjt_Categorias &cc) {
    if (b.empty()) {
        BinTree<partido> vacio;
        return vacio;
    }
    else{
        BinTree<partido> l = arbol_final (a.left(), b.left(),cj,ranking_local,prof+1,cat,cc);
        BinTree<partido> r = arbol_final (a.right(), b.right(),cj,ranking_local,prof+1,cat,cc);
        int participante1, participante2;
        if (a.left().left().empty()) participante1 = a.left().value();
        else participante1 = l.value().ganador;
        if (a.right().right().empty()) participante2 = a.right().value();
        else participante2 = r.value().ganador;
        partido p;
        p.primero = participante1;
        p.segundo = participante2;
        p.resultado = b.value();
        int puntos = cc.consultar_puntos(cat,prof);
        if(gana_izquierda(b.value(),cj,ranking_local,participante1,participante2)){
            p.ganador = participante1;
            cj.modificar_pg(ranking_local[participante1-1].first,1);
            cj.modificar_pp(ranking_local[participante2-1].first,1);
            ranking_local[participante2-1].second = puntos;
            
        }
        else {
            p.ganador = participante2;
            cj.modificar_pg(ranking_local[participante2-1].first,1);
            cj.modificar_pp(ranking_local[participante1-1].first,1);
            ranking_local[participante1-1].second = puntos;
        }
        
        if(prof == 1) ranking_local[p.ganador-1].second = cc.consultar_puntos(cat,0);
        
        BinTree<partido> q (p,l,r);
        return q;
    
    }
}

void escribir_arbol2(const BinTree<partido> &a, vector<pair<string,int> >& ranking_local){
    if (not a.empty()) {
        cout << '(' << a.value().primero << '.' << ranking_local[a.value().primero-1].first << " vs " << a.value().segundo << '.' << ranking_local[a.value().segundo-1].first << ' ' << a.value().resultado;
        escribir_arbol2(a.left(),ranking_local);
        escribir_arbol2(a.right(),ranking_local);
        cout << ')';
    }
}

void escribir_arbol(const BinTree<int> &a, vector<pair<string,int> >& ranking_local){
    if (a.left().empty()) cout << a.value() << '.' << ranking_local[a.value()-1].first;
    else {
        cout << '(';
        BinTree<int> l = a.left();
        escribir_arbol(l,ranking_local);
        cout << ' ';
        BinTree<int> r = a.right();
        escribir_arbol(r,ranking_local);
        cout << ')';
    }
}

void Torneo::iniciar(Cjt_Jugadores& cj){
    int n;
    cin >> n;
    ranking_local = vector<pair<string,int> > (n);
    for (int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;
        ranking_local[i].first = cj.consultar_jugador(pos);
    }
    double aux = log2 (n);
    int h = ceil(aux) + 1;
    int x = pow (2,h-1);
    cuadro_emparejamientos = crear_arbol(1,1,h,x-n);
    escribir_arbol(cuadro_emparejamientos,ranking_local);
    cout << endl;
    
}

void Torneo::eliminar_jugador(string id){
    int n = historial.size();
    for (int i = 0; i < n; ++i){
        if (historial[i].first == id) historial[i].second = 0;
    }
}

void Torneo::restar_puntos(Cjt_Jugadores &cj){
    int n = historial.size();
    for(int i = 0; i < n; ++i){
        if (cj.existe_jugador(historial[i].first)) cj.modificar_puntos(historial[i].first,-historial[i].second);
    }
}

void Torneo::finalizar(Cjt_Jugadores &cj,Cjt_Categorias &cc){
    BinTree<string> resultados = crear_resultados();
    BinTree<partido> cuadro_resultados = arbol_final(cuadro_emparejamientos, resultados,cj,ranking_local,1,c,cc);
    escribir_arbol2(cuadro_resultados,ranking_local);
    int n = ranking_local.size();
    cout << endl;
    for(int i = 0; i < n; ++i){
        cj.modificar_torneos(ranking_local[i].first,1);
        if (ranking_local[i].second != 0) {
            cout << i+1 << '.' << ranking_local[i].first << ' ' << ranking_local[i].second << endl;
            cj.modificar_puntos(ranking_local[i].first,ranking_local[i].second);
        }
    }
    int x = historial.size();
    for(int i = 0; i < x; ++i){
        if (historial[i].second != 0 and cj.existe_jugador(historial[i].first)){
            cj.modificar_puntos(historial[i].first,0-historial[i].second);
        }
    }
    vector<pair<string,int> > aux = ranking_local;
    historial = aux;
    cj.ordenar_ranking();
}
