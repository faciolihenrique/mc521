/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		   *
 * RA : 157986				       *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        *
 * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <math.h>

typedef enum {false, true} Boolean;

int main(){
    /*A vector for getting the number*/
    char number[3001];
    short int size = 0, j=1 , prev, current;
    Boolean i = True

    /*Reading*/
    scanf("%c",&number[size]);
    while(number[size] != '\n'){
        size++;
        scanf("%c",&number[size]);
    }

    /*Analysing*/
    /*Based on ascii table, 0 in char is 0...*/
    prev = number[0]
    current = number[j];
    while(current != size){
        /*Case of a negative number*/
        if(current == 45){
            j++;
            /*Numero negativo*/
            current = 0 - number[j];
        }
    }
}
