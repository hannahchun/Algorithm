#include <iostream>

using namespace std;

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

void bubble_sort(s_record a[], int n) {
    s_record temp;

    for (int j = n - 1 ; j >= 1 ; j--) {
       for (int k = 0 ; k < j ; k++) {
            if (a[k].s_id > a[k+1].s_id) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
       }
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

    bubble_sort(s_list, 12);
    show_list(s_list, n);
    return 0;
}