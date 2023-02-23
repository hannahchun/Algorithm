// Brute Force
#include <iostream>
#include <algorithm>

using namespace std;

int maxSubArraySum(int* arr, int n) {
    int maxSum = 0;
    int tempSum = 0;

    // Check whether all elements are negative
    int pos_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            pos_count++;
    }

    // If all elements are negative, return the largest element in the array
    if (pos_count == 0) {
        /* 정렬
        첫번째 인자 = 배열의 포인터
        두번째 인자 = 배열의 포인터 + 배열의 크기
        */ 
        sort(arr, arr + n);
        return arr[n - 1]; 
    }

    for (int i = 0 ; i < n ; i++) {
        tempSum = 0;
        for (int j = i ; j < n ; j++) {
            // tempSum은 현재의 인덱스 i에서 인덱스 j까지의 배열의 숫자의 합 저장
            tempSum += arr[j];
            if (tempSum > maxSum) 
                maxSum = tempSum;
        }
    }

    return maxSum;
}

int main() {
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    // int arr[8] = {-2, -3, -40, -11, -20, -10, -5, -3};

    cout << "The sum of the subarray with the largest sum : " << maxSubArraySum(arr, 8);
    cout << endl;

    return 0;
}