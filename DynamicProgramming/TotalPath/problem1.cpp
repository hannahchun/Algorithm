// Count all possible paths from top left to bottom right of a m x n matrix

// Recursion
#include <iostream>

using namespace std;

int numOfPaths (int m, int n) {
    // 종료 조건
    if (m == 0 && n == 0) // 방 (0, 0)
        return 0;
    if (m == 0 || n == 0) // 첫 행 또는 첫 열
        return 1; 
    
    // 재귀 호출
    return numOfPaths(m - 1, n) + numOfPaths(m, n - 1);
}

int main() {
    int m, n;

    cout << "Input m, n : ";
    cin >> m >> n;

    cout << "The number of all possible paths from top left to bottom right of a " << m << " x " << n << " matrix : " << numOfPaths(m - 1, n - 1);
    cout << endl;

    return 0;
}