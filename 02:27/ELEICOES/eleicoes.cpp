/*Henrique Noronha Facioli*/
#include <iostream>
#include <map>

using namespace std;

int main(){
    int tamanho, voto, aux, winner;
    map <int , int> politicos;

    map <int, int>::iterator it;

    cin >> tamanho;

    /*Insecao no map*/
    for(int i = 0; i < tamanho; i++){
        cin >> voto;
        if(politicos.count(voto)){
            politicos[voto] = politicos[voto] + 1;
        }else{
            politicos[voto] = 1;
        }
    }

    /*Faz a busca no map*/
    aux = 0;
    for (it = politicos.begin(); it != politicos.end(); ++it){
        if(it->second > aux){
            aux = it->second;
            winner = it->first;
        }
    }

    cout << winner << endl;

    return 0;
}
