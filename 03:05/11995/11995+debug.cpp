#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    queue<int> q;
    priority_queue<int> p_q;

    int times,option, in, out[1000], queue[1000], stack[1000], p_queue[1000];
    int cont , n , m ;
    int i;
    bool is_queue, is_p_queue, is_stack;


    cin >> times;

    while(1 == 1){
        is_queue = false, is_p_queue = false, is_stack = false;
        cont = 0, n = 0, m = 0;
        while(cont < times){
            cin >> option;
            if(option == 1){
                cin >> in;
                q.push(in);
                p_q.push(in);
                s.push(in);
                n++;
            }if(option == 2){
                cin >> out[m];
                m++;
            }
            cont++;
        }

        i = 0;
        while(!s.empty()){
            queue[i] = q.front();
            q.pop();
            stack[i] = s.top();
            s.pop();
            p_queue[i] = p_q.top();
            p_q.pop();
            i++;
        }

        for(i = 0; out[i] == queue[i] && i < m; i++){
            cout << "Queue " << queue[i] << " Out " << out[i] << endl;
            if(i == m-1){
                is_queue = true;
            }
        }
        for(i = 0; out[i] == p_queue[i] && i < m; i++){
            cout << "P_Queue " << p_queue[i] << " Out " << out[i] << endl;
            if(i == m-1){
                is_p_queue = true;
            }
        }

        for(i = 0; out[i] == stack[i] && i < m; i++){
            cout << "Stack " << stack[i] << " Out " << out[i] << endl;
            if(i == m-1){
                is_stack = true;
            }
        }

        cout << is_queue << is_p_queue << is_stack << endl;


        if( (is_queue && is_stack) || (is_queue && is_p_queue)  || (is_p_queue && is_stack) ){
            cout << "not sure" << endl;
        }else if(is_queue){
            cout << "queue" << endl;
        }else if(is_p_queue){
            cout << "priority queue" << endl;
        }else if(is_stack){
            cout << "stack" << endl;
        }else{
            cout << "impossible" << endl;
        }


        cin >> times;
        if(cin.eof()){
            break;
        }
    }
}
