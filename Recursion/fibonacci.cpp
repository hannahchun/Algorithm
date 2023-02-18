#include <iostream>

using namespace std;

int fibonacci(int n) {

    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);

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