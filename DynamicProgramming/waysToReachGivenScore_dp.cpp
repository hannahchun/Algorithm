// dp
#include <iostream>

using namespace std;

int waysToScore(int n) {
    // 변수를 사용해 선언한 배열은 초기화 불가
    // int arr[n + 1] = {0} 컴파일 에러 발생
    int arr[n + 1];
    
    for (int i = 0 ; i <= n ; i++) 
        arr[i] = 0;
    
    arr[0] = 1;

    for (int i = 1 ; i <= n ; i++) {
        if (i - 3 >= 0)
            arr[i] += arr[i - 3];
        if (i - 5 >= 0)
            arr[i] += arr[i - 5];
        if (i - 10 >= 0)
            arr[i] += arr[i - 10];
    }

    return arr[n];
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