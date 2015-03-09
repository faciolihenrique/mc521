/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		   *
 * RA : 157986				       *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        *
 * * * * * * * * * * * * * * * * * */
#include <stdio.h>

#define ABS(x) (x >= 0 ? x : -x)

typedef enum {false, true} Boolean;

int main(){
    /*A vector for getting the number*/
    int size, i, previous, current, absolute, number[2999];
    Boolean jolly;

    while(scanf("%d",&size) != EOF){
        jolly = true;
        for(i = 0; i < 3000; i++){
            number[i] = 0;
        }

        scanf("%d", &previous);

        for(i = 1; i < size; i++){
            scanf("%d", &current);

            absolute = ABS((previous-current));

            if(absolute >= size || absolute < 1 || number[absolute-1] == 1){
                jolly = false;
            }else{
                number[absolute-1] = 1;
            }

            previous = current;
        }

        for(i = 0; i < size-1; i++){
            if(number[i] != 1)
                jolly = false;
        }

        if(jolly){
            printf("Jolly\n");
        }else{
            printf("Not jolly\n");
        }
    }

    return 0;
}
