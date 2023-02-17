#include <iostream>

using namespace std;

void bubble_sort(int a[], int n) {
    int temp;

    // 종료 조건
    if (n == 1)
        return;

    // 1회의 탐색 과정 수행
    for (int j = 0 ; j < n - 1 ; j++) {
        if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            /* swap(a[j], a[j + 1]); */
        }
    }

    // 더 작은 범위의 인수로 재귀 호출
    bubble_sort(a, n-1);

    /* 재귀함수 사용하지 않은 풀이
    int temp;
    for (int j = 0 ; j < n - 1 ; j++) {
       for (int k = 0 ; k < n - j - 1 ; k++) {
            if (a[k] > a[k + 1]) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
       }
    } */
}

int main(){
    int list[5] = {15, 11, 17, 18, 9};
    int n = 5;

    // bubble sort로 오름차순 정렬하기
    bubble_sort(list, n);
    
    for(int i = 0 ; i < n ; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}