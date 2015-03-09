#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int numero_braceletes;
    string bracelete, magica, bracelete_inverso;

    cin >> numero_braceletes;

    for(int j = 0; j < numero_braceletes; j++){
        /*leitura braceletes*/
        cin >> magica;
        cin >> bracelete;

        bracelete += bracelete;


        bracelete_inverso = bracelete;
        reverse(bracelete_inverso.begin(),bracelete_inverso.end());

        /*for(int i = 0; i < bracelete.length(); i++){
            bracelete_inverso += bracelete[bracelete.length()-i-1];
        }*/

        if(bracelete.find(magica) != string::npos || bracelete_inverso.find(magica) != string::npos){
            cout << "S" << bracelete << endl;
        }else{
            cout << "N" << endl;
        }
    }

    return 0;
}
