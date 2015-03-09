/*Henrique Noronha Facioli*/

#include <iostream>

using namespace std;

bool fry_or_sat(int i){
    if((i-6)%7 == 0 || i%7 == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n_input, days,n_parties, hartal_parameter, day_of_hartal[3650];
    int number_of_hartal;
    int i,j;
    cin >> n_input;

    for(int testes = 0; testes < n_input; testes++){
        cin >> days;
        cin >> n_parties;

        for(i = 0; i < days; i++){
            day_of_hartal[i] = 0;
        }

        for(j = 0; j < n_parties; j++){
            cin >> hartal_parameter;

            for(i = 1; hartal_parameter*i <= days; i++){
                day_of_hartal[((hartal_parameter*i)-1)] = 1;
            }
        }
        number_of_hartal = 0;
        for(i = 0; i < days; i++){
            if(day_of_hartal[i] == 1 && fry_or_sat((i+1)) == false){
                number_of_hartal++;
            }
        }
        cout << number_of_hartal;
        cout << "\n";
    }
}
