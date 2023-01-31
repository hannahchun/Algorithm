// Sort integers in ascending order
// Solution 2

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> & list, int left, int mid, int right){
    vector<int> sorted_list(list.size());
    int i = left, j = mid+1, idx = left;

    while(i <= mid && j <= right){
        if(list[i] <= list[j]){
            sorted_list[idx++] = list[i++];
        }
        else{
            sorted_list[idx++] = list[j++];
        }
    }

    while(i <= mid){
        sorted_list[idx++] = list[i++];
    }
  
    while(j <= right){
        sorted_list[idx++] = list[j++];
    }
  
    for(int z = left ; z <= right ; z++){
        list[z] = sorted_list[z];
    }
}
 
void partition(vector<int> & list, int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        partition(list, left, mid);
        partition(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

void show_list(vector<int> & list, int n){
    for(int i = 0 ; i < list.size() ; i++){
        cout<<list.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(4);
    v.push_back(6);
    v.push_back(3);
    v.push_back(2);
    v.push_back(8);
    v.push_back(7);

    partition(v, 0, 5);
    show_list(v, 6);
    return 0;
}