// ID를 기준으로 학생들을 오름차순 정렬
// Solution 2

#include <iostream>

using namespace std;

#define SIZE 100

class s_record{
    public:
        string s_id;
        string name;
        double score;
        void set_data(string n1, string n2, double s);
};

void s_record::set_data(string n1, string n2, double s){
    s_id = n1;
    name = n2;
    score = s;
}

void merge(s_record list[], int left, int mid, int right){
    s_record sorted_list[SIZE];
    int i = left, j = mid+1, idx = left;

    while(i <= mid && j <= right){
        if(list[i].s_id <= list[j].s_id){
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
 
void partition(s_record list[], int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        partition(list, left, mid);
        partition(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

void show_list(s_record a[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<a[i].s_id<<":";
        cout<<a[i].name<<":";
        cout<<a[i].score<<endl;
    }
}

int main(){
    s_record s_list[12] = { {"21900013", "Kim", 6.5}, {"21900136", "Lee", 8.8 }, {"21900333", "Park", 9.2 },
                            { "21800442", "Choi", 7.1}, {"21900375", "Ryu", 5.4  }, {"21700248", "Cho", 6.3 },
                            { "21700302", "Jung", 8.3}, {"21800255", "Han", 6.9  }, {"21800369", "Kang", 6.3 },
                            { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };

    partition(s_list, 0, 11);
    show_list(s_list, 12);
    return 0;
}