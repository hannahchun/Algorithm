// dp

#include <iostream>

using namespace std;

int maxSubStringLength(char *str) {
    int n = strlen(str);
    int maxLen = 0;

    // sum[i][j] = 인덱스 i에서 인덱스 j까지의 숫자의 합
    // i > j 경우의 값은 사용하지 않음, 따라서 행렬의 대각선 아래쪽은 사용하지 않음
    int sum[n][n]; 

    // 대각선 위치의 값을 채워 넣음
    for (int i = 0 ; i < n ; i++) 
        sum[i][i] = str[i] - '0';
    
    // 대각선 위쪽 값을 채워 넣음
    for (int len = 2 ; len <= n ; len++) {
        for (int i = 0 ; i < n - len + 1 ; i++) {
            // i : 부분 문자열의 시작 인덱스
            // j : 부분 문자열의 끝 인덱스
            int j = i + len - 1; 
            int k = len / 2;

            // sum[i][j]의 값을 계산
            sum[i][j] = sum[i][j - k] + sum[j - k + 1][j];

            // len이 짝수이고, 왼쪽과 오른쪽 절반의 합이 같고, len가 maxLen보다 크면 maxLen 갱신
            if (len % 2 == 0 && sum[i][j - k] == sum[j - k + 1][j] && len > maxLen)
                maxLen = len;
        }
    }
    
    return maxLen;
    
}

int main(){
    char s[10];
    
    cout << "숫자로 이루어진 문자열 입력 : ";
    cin >> s;
    cout << "조건에 맞는 부분 문자열의 길이 : " << maxSubStringLength(s);
    cout << endl;

    return 0;
}