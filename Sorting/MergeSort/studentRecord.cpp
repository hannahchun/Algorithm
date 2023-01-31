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

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4) {
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;

    while ((i <= n2) && (j <= n4)) {
        if (a[i].s_id <= a[j].s_id)
            b[k ++] = a[i ++];
        else
            b[k ++] = a[j ++];
    }

    if (i > n2) {
        for (t = j ; t <= n4 ; t ++)
            b[t] = a[t];
    }
    else {
        for (t = i ; t <= n2 ; t ++)
            b[k + t - i] = a[t];
    }
}

void merge_pass(s_record a[], s_record b[], int n, int s) {
    int i, j;
    for (i = 0 ; i < (n - 2 * s + 1) ; i += 2 * s)
        merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    if (i + s <= n)
        merge(a, b, i, i + s - 1, i + s, n);
    else {
        for (j = i ; j <= n ; j ++)
            b[j] = a[j];  
    }
}

void merge_sort(s_record a[], int n) {
    int s = 1;
    s_record b[SIZE];

    while (s < n) {
        merge_pass(a, b, n - 1, s);
        s *= 2;
        merge_pass(b, a, n - 1, s);
        s *= 2;
    }
}

void show_list(s_record a[], int n) {
    for(int i = 0 ; i < n ; i ++) {
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

    merge_sort(s_list,n);
    show_list(s_list, n);
    return 0;
}