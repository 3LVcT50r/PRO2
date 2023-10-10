#include "Cjt_Categorias.hh"

Cjt_Categorias::Cjt_Categorias(){
}

bool Cjt_Categorias::existe_categoria(int c) const{
  if ( c<=vcat.size() and c > 0) return true;
  else return false;
}

string Cjt_Categorias::consultar_categoria(int c) const{
    return nom_cat[c-1];
}

int Cjt_Categorias::consultar_puntos(int c, int n) const{
    return vcat[c-1][n];
}

void Cjt_Categorias::leer(){
    int c, k;
    cin >> c >> k;
    nom_cat = vector<string> (c);
    for (int i = 0; i < c; ++i) {
        cin >> nom_cat[i];
    }
    vcat = vector<vector<int> > (c,vector<int>(k));
    for (int j = 0; j < c; ++j){
        for (int l = 0; l < k; ++l) {
            cin >> vcat[j][l];
        }
    }
}

void Cjt_Categorias::escribir() const{
    int n = vcat.size();
    int k = vcat[0].size();
    cout << n << ' ' << k << endl;
    for (int i = 0; i < n; ++i){
        cout << nom_cat[i];
        for (int j = 0; j < k; ++j) {
            cout << ' ' << vcat[i][j];
        }
        cout << endl;
    }

}
