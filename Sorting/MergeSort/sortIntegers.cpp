// Sort integers in ascending order
// Solution 1

#include <iostream>
using namespace std;

#define SIZE 10

void merge(int a[], int b[], int n1, int n2, int n3, int n4){
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;

    while((i <= n2) && (j <= n4)){
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    if(i > n2){
        for(t = j ; t <= n4 ; t++)
            b[t] = a[t];
    }
    else{
        for(t = i ; t <= n2 ; t++)
            b[k+t-i] = a[t];
    }
}

void merge_pass(int a[], int b[], int n, int s){
    int i, j;
    for(i = 0 ; i < (n-2*s+1) ; i += 2*s)
        merge(a, b, i, i+s-1, i+s, i+2*s-1);
    if(i+s <= n)
        merge(a, b, i, i+s-1, i+s, n);
    else{
        for(j = i ; j <= n ; j++)
            b[j] = a[j];  
    }
}

void merge_sort(int a[], int n){
    int s = 1;
    int b[SIZE];

    while(s < n){
        merge_pass(a, b, n-1, s);
        s *= 2;
        merge_pass(b, a, n-1, s);
        s *= 2;
    }
}

void show_list(int a[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int list[6] = {4, 6, 3, 2, 8, 7};

    int n = 6;

    merge_sort(list,n);
    show_list(list, n);
    return 0;
}