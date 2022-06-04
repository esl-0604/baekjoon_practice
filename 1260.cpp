#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> node[1001];
int N, M, V;

void DFS (int start){
    int current, next;
    bool expanded[1001] = {false, };
    stack<int> fringe;
    fringe.push(start);
   
    while(!fringe.empty()){
        current = fringe.top();
        fringe.pop();

        if(expanded[current] == false){
            cout << current << ' ';
            expanded[current] = true;
            int length = node[current].size();

            for(int k=length-1; k>=0; k--){
                next = node[current][k];
                if(expanded[next] == false){
                    fringe.push(next);
                }
            }
        }
    }
}

void BFS (int start){
    int current, next;
    bool expanded[1001] = {false, };
    queue<int> fringe;
    fringe.push(start);
   
    while(!fringe.empty()){
        current = fringe.front();
        fringe.pop();

        if(expanded[current] == false){
            cout << current << ' ';
            expanded[current] = true;
            int length = node[current].size();

            for(int k=0; k<length; k++){
                next = node[current][k];
                if(expanded[next] == false){
                    fringe.push(next);
                }
            }
        }
    }
}


int main(){

    int i, j;
    cin >> N >> M >> V;

    for(int t=0; t<M; t++){
        cin >> i >> j;
        node[i].push_back(j);
        node[j].push_back(i);
    } 

    for(int t=1; t<=N; t++){
        sort(node[t].begin(), node[t].end());
    }

    DFS(V);
    cout << '\n';
    BFS(V);
}