// Recursion
#include <iostream>

using namespace std;

int countWays(int n) {
    // 종료 조건
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n; 

    cout << "Input n : ";
    cin >> n;

    cout << "Number of ways to arrange tiles on a 2*n board : " << countWays(n);
    cout << endl;

    return 0;
}