#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string enter = "";

    cin >> enter;
    while(enter != "#"){
        if(next_permutation(enter.begin(),enter.end())){
            cout << enter << endl;
        }else{
            cout << "No Successor" << endl;
        }
        cin >> enter;
    }
    return 0;
}
