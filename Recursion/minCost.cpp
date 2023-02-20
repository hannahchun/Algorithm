#include <iostream>

using namespace std;

int cost[4][4] = { {0, 10, 75, 94}, {-1, 0, 35, 50}, {-1, -1, 0, 80}, {-1, -1, -1, 0} };

// 재귀 함수에 메모 전략 적용
int memo[4][4] = {0};

int minCost(int s, int d) {
    
    if (s == d || s == d - 1)
        return cost[s][d];

    // 값이 계산되지 않은 경우에만 블록 안으로 들어가서 계산
    if (memo[s][d] == 0) {
        int minValue = cost[s][d];

        for (int i = s + 1 ; i < d ; i++) {
            int temp = minCost(s, i) + minCost(i, d);
            if (temp < minValue)
                minValue = temp;
        }

        // 계산된 최소 요금을 캐시에 저장
        memo[s][d] = minValue;
    }

    return memo[s][d];

    /* 재귀 함수를 사용한 풀이 (메모 전략 X)
    // 출발역과 도착역이 같은 경우와 도착역이 출발역 바로 다음 역인 경우 두 역간의 최소 비용 정해져 있음
    if (s == d || s == d - 1)
        return cost[s][d];
    
    // 최솟값을 찾기 위해 모든 중간 역에 대해서 계산
    int minValue = cost[s][d];
    for (int i = s + 1 ; i < d ; i++) {
        //s번 역에서 i번 역까지의 최소 요금과 i번 역에서 d번 역까지의 최소 요금의 합
        int temp = minCost(s, i) + minCost(i, d);
        if (temp < minValue)
            minValue = temp;
    }
    return minValue; */
    
}

int main(){
    int n = 4;

    cout << "Minimum cost of " << n << " stations : " << minCost(0, n - 1);
    cout << endl;

    return 0;
}