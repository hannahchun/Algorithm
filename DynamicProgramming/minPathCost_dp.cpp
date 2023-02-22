// dp
#include <iostream>

using namespace std;

#define M 3
#define N 4

int cost[3][4] = { {1, 3, 5, 8}, {4, 2, 1, 7}, {4, 3, 2, 3} };

int MEM[M][N] = {0};

int getMin(int a, int b) {
    return a < b ? a : b;
}

int minPathCost(int cost[M][N]) {
    MEM[0][0] = cost[0][0];

    // 제일 위 행
    for (int j = 1 ; j < N ; j++) 
        MEM[0][j] = MEM[0][j - 1] + cost[0][j];
    
    // 제일 왼쪽 열
    for (int i = 1 ; i < M ; i++) 
        MEM[i][0] = MEM[i - 1][0] + cost[i][0];
    
    // 나머지 셀 채우기
    for (int i = 1 ; i < M ; i++) {
        for (int j = 1 ; j < N ; j++) 
            MEM[i][j] = getMin(MEM[i - 1][j], MEM[i][j - 1]) + cost[i][j];
    }

    return MEM[M - 1][N - 1];
}

int main() {

    cout << "Minimum travel cost : " << minPathCost(cost);
    cout << endl;

    return 0;
}