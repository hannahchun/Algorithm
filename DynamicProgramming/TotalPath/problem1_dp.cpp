// Count all possible paths from top left to bottom right of a m x n matrix

// dp
#include <iostream>

using namespace std;

int numOfPaths (int m, int n) {
    int cache[m][n];

    // 첫번째 열
    for (int i = 1 ; i < m ; i++)
        cache[i][0] = 1;

    // 첫번째 행
    for (int j = 1 ; j < n ; j++)
        cache[0][j] = 1;
    
    // 나머지 셀
    for (int i = 1 ; i < m ; i++) {
        for (int j = 1 ; j < n ; j++)
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1];
    }

    return cache[m - 1][n - 1];
}

int main() {
    int m, n;

    cout << "Input m, n : ";
    cin >> m >> n;

    cout << "The number of all possible paths from top left to bottom right of a " << m << " x " << n << " matrix : " << numOfPaths(m, n);
    cout << endl;

    return 0;
}