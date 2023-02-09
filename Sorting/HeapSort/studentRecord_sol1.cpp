// 1번째 원소부터 채워진 heap이라고 가정했을 때
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
    child = 2 * troot;

    while (child <= size) {
        if ( (child < size) && (a[child].s_id < a[child + 1].s_id) )
            child++;
        if (tmpkey > a[child].s_id)
            break;
        else {
            a[child / 2] = a[child];
            child *= 2;
        }
    }
    a[child / 2] = tmp;
}

void heap_sort(s_record a[], int n) {
    int i;
    s_record b[SIZE], temp;

    // 1번째부터 n번째까지로 위치 조정
    for (i = 0 ; i < n ; i++)
        b[i + 1] = a[i];

    // 초기 heap 구성
    for (i = n / 2 ; i > 0 ; i--)
        adjust(b, i, n);

    // 정렬
    for (i = n - 1 ; i > 0 ; i--) {
        // heap에서 첫원소와 끝원소의 위치를 교환
        temp = b[1];
        b[1] = b[i + 1];
        b[i + 1] = temp;
        // heap 의 size를 1 감소 시킴
        // root 를 기준으로 reheaping(adjust)
        adjust(b, 1, i);
    }

    // 정렬된 결과를 다시 배열 a에 담음
    for(i = 1 ; i <= n ; i++)
        a[i - 1] = b[i];
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