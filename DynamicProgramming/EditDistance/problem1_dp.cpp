// Given two strings str1 and str2 and operations (Insert, Remove, Replace) that can be performed on str1, 
// find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

// dp
#include <iostream>

using namespace std;

int getMinimum(int a, int b, int c) {
    if (a >= c && b >= c)
        return c;
    return a > b ? b : a;
}

int editDistance(char* str1, char* str2, int m, int n) {
    int EditD[m + 1][n + 1];

    // 제일 위 행
    for (int j = 0 ; j <= n ; j++)
        EditD[0][j] = j;

    // 제일 왼쪽 열
    for (int i = 0 ; i <= m ; i++)
        EditD[i][0] = i;
    
    // 나머지
    for (int i = 1 ; i <= m ; i++) {
        for (int j = 1 ; j <= n ; j++) {

            // 두 글자가 같다면 
            if (str1[i - 1] == str2[j - 1])
                EditD[i][j] = EditD[i - 1][j - 1];
            
            // 두 글자가 다르다면
            else
                EditD[i][j] = getMinimum(EditD[i][j - 1], EditD[i - 1][j], EditD[i - 1][j - 1]) + 1;
        }
    }

    return EditD[m][n];
}

int main() {
    char s1[20]; 
    char s2[20]; 
    int s1Len;
    int s2Len;

    cout << "Input word1 : ";
    cin >> s1;

    s1Len = strlen(s1);

    cout << "Input word2 : ";
    cin >> s2;

    s2Len = strlen(s2);

    cout << "The minimum number of operations required to convert word1 to word2 : " << editDistance(s1, s2, s1Len, s2Len);
    cout << endl;

    return 0;
}