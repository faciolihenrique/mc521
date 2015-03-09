#include <iostream>
#include <sstream>
#include <string>

#define TAM 100

using namespace std;

bool ataca(int casa,int vizinha, int n_herdeiro){
    if(vizinha == casa + 1){
        return true;
    }
    if(casa == n_herdeiro-1 && vizinha == 0){
        return true;
    }
    return false;
}

void imprimir(int matriz[TAM][TAM], int linha, int coluna){
    for(int i = 0; i < linha; i++){
        cout<< matriz[i][0];
        for(int j = 1; j < coluna; j++){
            cout << " " << matriz[i][j];
        }
        cout << endl;
    }
}

void checar_vizinhanca(int n_herdeiro, int matriz[TAM][TAM],int linha, int coluna, int vezes, int foram){
    int terreno[TAM][TAM];

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            terreno[i][j] = matriz[i][j];
        }
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(ataca(matriz[i][j], matriz[i-1][j], n_herdeiro) && i > 0){
                terreno[i-1][j] = matriz[i][j];
            }
            if(ataca(matriz[i][j], matriz[i+1][j], n_herdeiro) && i < linha-1){
                terreno[i+1][j] = matriz[i][j];
            }
            if(ataca(matriz[i][j], matriz[i][j-1], n_herdeiro) && j > 0){
                terreno[i][j-1] = matriz[i][j];
            }
            if(ataca(matriz[i][j], matriz[i][j+1], n_herdeiro) && j < coluna-1){
                terreno[i][j+1] = matriz[i][j];
            }
        }
    }

    if(foram < vezes-1){
        checar_vizinhanca(n_herdeiro, terreno, linha ,coluna , vezes, ++foram);
        return;
    }

    imprimir(terreno, linha, coluna);
}

int main(){
    int terreno[TAM][TAM];
    int linha, coluna, n_herdeiros, n_batalhas;

    cin >> n_herdeiros >> linha >> coluna >> n_batalhas;

    while((n_herdeiros != 0) && (linha != 0) && (coluna != 0 ) && (n_batalhas != 0)){
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                cin >> terreno[i][j];
            }
        }

        checar_vizinhanca(n_herdeiros, terreno,linha, coluna, n_batalhas, 0);

        cin >> n_herdeiros >> linha >> coluna >> n_batalhas;
    }

    return 0;
}
