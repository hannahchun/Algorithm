#include <iostream>

using namespace std;

int sum (int n) {
    // 첫 번째 종료 조건
    if (n <= 0)
        return 0;
    // 두 번째 종료 조건
    if (n == 1)
        return 1;
    return n + sum(n-1); 

    // 짧게 고쳐 쓴 코드
    // return (n <= 0) ? 0: ((n == 1) ? 1: (n + sum(n-1)));
}

int main(){
    int n;

    cout<<"n 입력: ";
    cin>>n;

    cout<<"1부터 n까지의 합: "<<sum(n)<<endl;
    return 0;
}