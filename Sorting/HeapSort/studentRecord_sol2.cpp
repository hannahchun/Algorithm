// 0번째 원소부터 채워진 heap이라고 가정했을 때
#include <iostream>

using namespace std;

#define SIZE 100

class s_record {
    public:
        string s_id;
        string name;
        double score;
        void set_data(string n1, string n2, double s);
};

void s_record::set_data(string n1, string n2, double s) {
    s_id = n1;
    name = n2;
    score = s;
}

void adjust(s_record a[], int troot, int size) {
    s_record tmp;
    string tmpkey;
    int child;

    tmp = a[troot];
    tmpkey = a[troot].s_id;
    child = 2 * troot + 1;

    while (child <= size) {
        if ( (child < size) && (a[child].s_id < a[child + 1].s_id) )
            child++;
        if (tmpkey > a[child].s_id)
            break;
        else {
            a[(child - 1) / 2] = a[child];
            child = child * 2 + 1;
        }
    }
    a[(child - 1) / 2] = tmp;
}

void heap_sort(s_record a[], int n) {
    int i;
    s_record temp;

    int size = n - 1;

    // 초기 heap 구성
    for (i = (size - 1) / 2 ; i >= 0 ; i--)
        adjust(a, i, size);

    // 정렬
    for (i = size - 1 ; i >= 0 ; i--) {
        // heap에서 첫원소와 끝원소의 위치를 교환
        temp = a[0];
        a[0] = a[i + 1];
        a[i + 1] = temp;
        // heap 의 size를 1 감소 시킴
        // root 를 기준으로 reheaping(adjust)
        adjust(a, 0, i);
    }
}

void show_list(s_record a[], int n) {
    for(int i = 0 ; i < n ; i++) {
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
    int n = 12;

    heap_sort(s_list, n);
    show_list(s_list, n);
    return 0;
}