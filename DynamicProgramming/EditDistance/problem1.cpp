// Given two strings str1 and str2 and operations (Insert, Remove, Replace) that can be performed on str1, 
// find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

// Recursion
#include <iostream>

using namespace std;

int getMinimum(int a, int b, int c) {
    if (a >= c && b >= c)
        return c;
    return a > b ? b : a;
}

int editDistance(char* str1, char* str2) {
    // str1이 빈 문자열이면 str2의 모든 글자 삽입
    if (str1 == NULL || *str1 == '\0')
        return strlen(str2);
    // str2가 빈 문자열이면 str1의 모든 글자 삽입
    if (str2 == NULL || *str2 == '\0')
        return strlen(str1);

    // 첫 번째 글자가 같으면 첫번째 글자를 무시하고 나머지 단어 간의 최소 교정 비용 구함
    if(*str1 == *str2)
        return editDistance(str1 + 1, str2 + 1);
    
    // 세가지 연산 후, 최소 교정 비용 구해
    int d, u, i;
    // 삭제
    // 원래 : str1의 첫번째 글자 삭제
    // 코드 : str1의 첫번째 글자 제외하고, str1과 str2 사이의 최소 교정 비용 구해
    d = editDistance(str1 + 1, str2);
    // 치환
    // 원래 : str1의 첫번째 글자 str2의 첫번째 글자로 치환
    // 코드 : str1과 str2의 첫번째 글자 제외하고, str1과 str2 사이의 최소 교정 비용 구해
    u = editDistance(str1 + 1, str2 + 1);
    // 삽입
    // 원래 : str2의 첫번째 글자 str1의 제일 앞에 삽입
    // 코드 : str2의 첫번째 글자 제외하고, str1과 str2 사이의 최소 교정 비용 구해
    i = editDistance(str1, str2 + 1);

    // 세 연산 이후 최소 교정 비용 간의 최솟값에 1 더하여 반환
    return getMinimum(d, u, i) + 1;
}

int main() {
    char s1[20]; 
    char s2[20]; 

    cout << "Input word1 : ";
    cin >> s1;

    cout << "Input word2 : ";
    cin >> s2;

    cout << "The minimum number of operations required to convert word1 to word2 : " << editDistance(s1, s2);
    cout << endl;

    return 0;
}