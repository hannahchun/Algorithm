// 완전탐색 (brute-force)

#include <iostream>

using namespace std;

int maxSubStringLength(char *str) {
    int n = strlen(str);
    int maxLen = 0;

    // i : 부분 문자열의 시작 인덱스
    for (int i = 0 ; i < n ; i++) {

        // j : 부분 문자열의 끝 인덱스 (짝수 길이)
        for (int j = i + 1 ; j < n ; j += 2) {
            // len : 현재 부분 문자열의 길이
            int len = j - i + 1;

            // 지금까지의 maxLen가 검사하려는 문자열보다 길면 현재 문자열을 검사하지 않음
            if (maxLen >= len)
                continue;
            
            int lSum = 0, rSum = 0; 
            for (int k = 0 ; k < len / 2 ; k++) {
                lSum += (str[i + k] - '0');
                rSum += (str[i + k + len / 2] - '0');
            }

            if (lSum == rSum)
                maxLen = len;
        }
    }

    return maxLen;
}

int main() {
    char s[10]; //숫자로 이루어진 문자열

    cout << "숫자로 이루어진 문자열 입력 : ";
    cin >> s;
    cout << "조건에 맞는 부분 문자열의 길이 : " << maxSubStringLength(s);
    cout << endl;

    return 0;
}