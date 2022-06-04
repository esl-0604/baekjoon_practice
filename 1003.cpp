#include <iostream>
using namespace std;

int num0, num1;
int list[40];

int fibonacci(int n) {
    if (n == 0) {
        // printf("0");
        num0++;
        return 0;
    } else if (n == 1) {
        // printf("1");
        num1++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){

    int a;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> list[i];
    }
    for(int i=0; i<N; i++){
        num0 = 0;
        num1 = 0;
        a = fibonacci(list[i]);
        cout << num0 << ' ' << num1 << '\n';
    }
}