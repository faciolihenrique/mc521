/*Henrique Noronha Facioli*/
#include <stdio.h>

#define TAMMAX 100000

typedef struct{
    int numero_candidato;
    int numero_votos;
} Candidato;

typedef struct {
    Candidato vetor[TAMMAX];
    int tam;
} Heap;

void Desce(Heap *h, int m) {
    int k = 2*m+1;
    Candidato x = (*h).vetor[m];
    while (k<(*h).tam) {
        if ((k<((*h).tam)-1) && (((*h).vetor[k]).numero_votos < ((*h).vetor[k+1]).numero_votos))
            k++;
        if (x.numero_votos < ((*h).vetor[k]).numero_votos) {
            (*h).vetor[m] = (*h).vetor[k];
            m=k;
            k = 2*k+1;
        } else break ;
    }
    (*h).vetor[m] = x;
} /* Desce */

void ConstroiHeap(Heap *h) {
    int i;
    for (i = ((*h).tam-2)/2; i>=0; i--)
        Desce(h, i);
} /* ConstroiHeap2 */

int main(){
    Heap votacao;
    int tamanho, voto, achou;
    int i, j;

    scanf("%d", &tamanho);

    /*Comeca a insercao dos elementos no heap*/
    scanf("%d", &voto);

    (votacao.vetor[0]).numero_candidato = voto;
    (votacao.vetor[0]).numero_votos = 1;
    votacao.tam = 1;

    for(i = 1; i < tamanho; i++){
        achou = 0;
        scanf("%d", &voto);

        /*Faz a busca no heap para a insercao*/
        for(j = 0; j <= votacao.tam && !achou; j++){
            if( (votacao.vetor[j]).numero_candidato == voto){
                (votacao.vetor[j]).numero_votos++;
                achou = 1;
            }else if(j == (votacao.tam)){
                (votacao.vetor[j]).numero_candidato = voto;
                (votacao.vetor[j]).numero_votos = 1;
                votacao.tam++;
                achou = 1;
            }
        }
    }


    ConstroiHeap(&votacao);

    printf("%d\n",(votacao.vetor[0]).numero_candidato );

    return 0;
}
