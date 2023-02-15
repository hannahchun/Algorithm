#include <iostream>

using namespace std;

int power (int x, int n) {
    // 첫 번째 종료 조건
    if (n == 0)
        return 1;
    // 두 번째 종료 조건
    else if (x == 1)
        return x;
    else
        return x * power(x, n-1); 
}

int main(){
    int x, n;

    cout<<"x 입력 : ";
    cin>>x;
    cout<<"n 입력 : ";
    cin>>n;

    cout<<"x to the power of n : "<<power(x, n)<<endl;
    return 0;
}