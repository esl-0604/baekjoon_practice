#include <iostream>
#include <queue>


using namespace std;

struct position{
    int x;
    int y;
    int step;
};

int box[1001][1001] = {0, };

int N, M;

// 토마토가 다 익었는지 판단해주는 함수
   // -1 : 안익은 토마토가 있음
   //  0 : 다 익음
int IsGood(){ 
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(box[i][j] == 0){
                return -1;
            }
        }
    }
    return 0;
}

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