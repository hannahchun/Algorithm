// Recursion
#include <iostream>

using namespace std;

int waysToScore(int n) {
    // 종료 조건
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    
    return waysToScore(n - 10) + waysToScore(n - 5) + waysToScore(n - 3);
}

int main() {
    int n; 

    cout << "Target score : ";
    cin >> n;

    cout << "Players can score 3, 5, or 10 points" << endl;
    cout << "Number of ways to reach target score : " << waysToScore(n);
    cout << endl;

    return 0;
}