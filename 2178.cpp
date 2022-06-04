#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct position{
    int x;
    int y;
    int step;
};

string s;
int maze[102][102] = {0, };
int N, M;

int BFS (){
    position current, next;
    bool expanded[102][102] = {false, };
    queue<position> fringe;

    current = {1, 1, 1};
    fringe.push(current);
   
    while(!fringe.empty()){
        current = fringe.front();
        fringe.pop();

        if(expanded[current.x][current.y] == false){
            expanded[current.x][current.y] = true;
            
            if(current.x == N && current.y == M){
                break;;
            }

            if(maze[current.x-1][current.y] == 1 && expanded[current.x-1][current.y] == false){
                next = {current.x-1, current.y, current.step+1};
                fringe.push(next);  
            }
            if(maze[current.x+1][current.y] == 1 && expanded[current.x+1][current.y] == false){
                next = {current.x+1, current.y, current.step+1};
                fringe.push(next);  
            }if(maze[current.x][current.y-1] == 1 && expanded[current.x][current.y-1] == false){
                next = {current.x, current.y-1, current.step+1};
                fringe.push(next);  
            }
            if(maze[current.x][current.y+1] == 1 && expanded[current.x][current.y+1] == false){
                next = {current.x, current.y+1, current.step+1};
                fringe.push(next);  
            }   
        }
    }
    return current.step;
}


int main(){

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        cin >> s;
        for(int j=1; j<=M; j++){
            maze[i][j] = (int)(s[j-1] - '0');
        }
    }

    int p = BFS();
    cout << p <<'\n';
}