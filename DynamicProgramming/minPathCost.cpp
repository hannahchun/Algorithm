// Recursion
#include <iostream>

using namespace std;

#define M 3
#define N 4

int cost[3][4] = { {1, 3, 5, 8}, {4, 2, 1, 7}, {4, 3, 2, 3} };

int getMin(int a, int b) {
    return a < b ? a : b;
}

int minPathCost(int cost[M][N], int m, int n) {
    // 셀 (0, 0)이 목적지인 경우
    if (m == 0 && n == 0)
        return cost[0][0];
    // 목적지가 제일 위 행에 있을 때
    if (m == 0)
        return minPathCost(cost, 0, n - 1) + cost[0][n];
    // 목적지가 제일 왼쪽 열에 있을 때
    if (n == 0)
        return minPathCost(cost, m - 1, 0) + cost[m][0];
    
    int x = minPathCost(cost, m - 1, n);
    int y = minPathCost(cost, m, n - 1);

    // getMin()은 두 수 중 작은 수를 반환하는 도우미 함수
    return getMin(x, y) + cost[m][n];
}

int main() {

    cout << "Minimum travel cost : " << minPathCost(cost, 2, 3);
    cout << endl;

    return 0;
}