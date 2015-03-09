#include <iostream>

using namespace std;

int main(){
    int numbers, read[10001], i, n_peacks, first_derivate;
    bool desce, sobe;

    cin >> numbers;

    while(numbers != 0){
        n_peacks = 1;
        desce = false;
        sobe = false;

        for(i =0 ; i < numbers; i++){
            cin >> read[i];
        }
        read[i] = read[0];

        if(read[0] - read[1] > 0){
            first_derivate = -1;
        }else{
            first_derivate = 1;
        }

        i = 0;
        while(i != numbers){
            while(read[i+1] < read[i] && i != numbers){
                i++;
                desce = true;
            }
            if(desce && i != numbers){
                desce = false;
                n_peacks++;
            }
            while(read[i+1] > read[i] && i != numbers){
                i++;
                sobe = true;
            }
            if(sobe && i != numbers){
                sobe = false;
                n_peacks++;
            }
        }

        /*Caso a primeira derivada entre o ultimo e o primeiro seja do mesmo tipo */
        if((read[numbers-1] > read[numbers] && first_derivate == -1) || (read[numbers-1] < read[numbers] && first_derivate == 1)){
            cout << n_peacks-1 << endl;
        }else
            cout << n_peacks << endl;

        cin >> numbers;
    }

}
