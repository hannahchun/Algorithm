// dp
#include <iostream>

using namespace std;

int countWays(int n) {
    int arr[n + 1];
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3 ; i <= n ; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    } 

    return arr[n];
}

int main() {
    int n; 

    cout << "Input n : ";
    cin >> n;

    cout << "Number of ways to arrange tiles on a 2*n board : " << countWays(n);
    cout << endl;

    return 0;
}