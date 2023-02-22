// Memoization
#include <iostream>

using namespace std;

#define M 3
#define N 4

int cost[3][4] = { {1, 3, 5, 8}, {4, 2, 1, 7}, {4, 3, 2, 3} };

int MEM[M][N] = {0};

int getMin(int a, int b) {
    return a < b ? a : b;
}

int minPathCost(int cost[M][N], int m, int n) {
    // 만약 셀 (m, n)의 최소 이동 비용이 이미 계산되어 있다면 다시 계산하지 않음
    if (MEM[m][n] != 0)
        return MEM[m][n];
    
    // 계산된 결과는 MEM[m][n]에 저장한 다음, 이 값 반환
    // 셀 (0, 0)이 목적지인 경우
    if (m == 0 && n == 0)
        MEM[m][n] = cost[0][0];
    // 목적지가 제일 위 행에 있을 때
    else if (m == 0)
        MEM[m][n] = minPathCost(cost, m, n - 1) + cost[0][n];
    // 목적지가 제일 왼쪽 열에 있을 때
    else if (n == 0)
        MEM[m][n] = minPathCost(cost, m - 1, n) + cost[m][0];
    else {
        int x = minPathCost(cost, m - 1, n);
        int y = minPathCost(cost, m, n - 1); 
        MEM[m][n] = getMin(x, y) + cost[m][n];
    }

    return MEM[m][n];
}

int main() {

    cout << "Minimum travel cost : " << minPathCost(cost, 2, 3);
    cout << endl;

    return 0;
}