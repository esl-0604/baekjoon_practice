#include <iostream>
using namespace std;

int list[40];
int num0[41] = {0, };
int num1[41] = {0, };



void fibonacci() {
    num0[0] = 1;
    num0[1] = 0;
    num1[1] = 1;
    for(int i=2; i<41; i++){
        num0[i] = num0[i-1] + num0[i-2];
        num1[i] = num1[i-1] + num1[i-2];
    }
}

int main(){

    int a;
    int N;
    fibonacci();
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> list[i];
    }
    for(int i=0; i<N; i++){
        cout << num0[list[i]] << ' ' << num1[list[i]] << '\n';
    }
}