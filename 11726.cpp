#include <iostream>
using namespace std;

// 경우의 수를 저장할 리스트
int list[1000];

// 경우의 수를 미리 계산하여 리스트에 하나하나 저장해주는 함수
// N=1 ~ 1000 모든 경우의 수에 대하여 전부 계산
void step() {
    // N = 1,2인 경우는 미리 초기화
    list[0] = 1; 
    list[1] = 2;

    // 피보나치와 같은 원리로 쌓여가기 때문에 피보나치 알고리즘 적용.
    for(int i=2; i<1000; i++){
        list[i] = (list[i-1] + list[i-2]) % 10007; // 10007로 계속 나누어주어야 메모리 초과로 인한 'stack overflow' 에러 방지 가능
    }
}

int main(){
    int N;
    step();

    cin >> N;
    cout << list[N-1];
}