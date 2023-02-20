#include <iostream>

using namespace std;

// 재귀 함수에 메모 전략 적용
int memo[5] = {0};

int fibonacci(int n) {

    // 메모에 값이 있는 경우
    if(memo[n] != 0)
        return memo[n];
    
    // 메모에 값이 없는 경우
    if (n == 1 || n == 2)
        memo[n] = 1;
    else    
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    
    return memo[n];

    /* 재귀 함수를 사용한 풀이 (메모 전략 X)
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); */

    /* 재귀함수 사용하지 않은 풀이
    int a = 1, b = 1, c, cnt;

    if (n == 1 || n == 2)
        return 1;

    for (cnt = 3 ; cnt <= n ; cnt++) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c; */
}

int main(){
    int n = 5;

    cout << "Fibonacci of " << n << " : " << fibonacci(n);
    cout << endl;

    return 0;
}