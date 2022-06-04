#include <iostream>
#include <vector>

using namespace std;

struct step{
    int from;
    int to;
};

// step의 과정을 벡터로 표현
  // Ex. N=3
  // hanoi[3] == {[1, 2], [1, 3], [2,3]}
  // hanoi[3].size() == 3
vector<step> hanoi[21];



void Hanoi_Step(int N){
    step first, next;
    first.from = 1;
    first.to = 3;
    hanoi[1].push_back(first);
    int step_size;

    for(int i=2; i<=N; i++){
        step_size = hanoi[i-1].size(); // 하나 적은 개수의 하노이의 단계수

        for(int j=0; j<step_size; j++){
            if(hanoi[i-1][j].from == 1){
                next.from = 1;
            }
            else if(hanoi[i-1][j].from == 2){
                next.from = 3;
            }
            else{
                next.from = 2;
            }

            if(hanoi[i-1][j].to == 1){
                next.to = 1;
            }
            else if(hanoi[i-1][j].to == 2){
                next.to = 3;
            }
            else{
                next.to = 2;
            }
            hanoi[i].push_back(next);
        }
        next.from = 1;
        next.to = 3;
        hanoi[i].push_back(next);
        for(int j=0; j<step_size; j++){
            if(hanoi[i-1][j].from == 1){
                next.from = 2;
            }
            else if(hanoi[i-1][j].from == 2){
                next.from = 1;
            }
            else{
                next.from = 3;
            }

            if(hanoi[i-1][j].to == 1){
                next.to = 2;
            }
            else if(hanoi[i-1][j].to == 2){
                next.to = 1;
            }
            else{
                next.to = 3;
            }
            hanoi[i].push_back(next);
        }
    }
}

int main(){
    int N;

    cin >> N;
    
    Hanoi_Step(N);
    int size = hanoi[N].size();
    cout << size <<'\n';
    for(int i=0; i<size; i++){
        cout << hanoi[N][i].from << ' ' << hanoi[N][i].to << '\n';
    }
}