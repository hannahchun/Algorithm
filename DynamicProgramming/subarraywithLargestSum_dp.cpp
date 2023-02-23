// Kadane's algorithm
// employs a simple form of Dynamic Programming to solve “the largest contiguous elements in an array” with a runtime of O(n)
#include <iostream>
#include <algorithm>

using namespace std;

int maxSubArraySum(int* arr, int n) {
    int maxSumEndingHere = 0;
    int maxSumSoFar = 0;

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
        maxSumEndingHere = maxSumEndingHere + arr[i];
        if (maxSumEndingHere < 0)
            maxSumEndingHere = 0;
        if (maxSumSoFar < maxSumEndingHere)
            maxSumSoFar = maxSumEndingHere;
    }

    return maxSumSoFar;
}

int main() {
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    // int arr[8] = {-2, -3, -40, -11, -20, -10, -5, -3};

    cout << "The sum of the subarray with the largest sum : " << maxSubArraySum(arr, 8);
    cout << endl;

    return 0;
}