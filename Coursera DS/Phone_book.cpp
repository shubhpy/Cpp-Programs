#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Query {
    string type, name;
    int number;
};


int main(){
    int n;
    int max_no = 9999999;

    vector<string> all_numbers(max_no);
    for (int i = 0; i < max_no; i++) {
        all_numbers[i]="a";
        }

    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;

    }

    for (int i = 0; i < n; ++i) {
        if (queries[i].type == "add")
            all_numbers[queries[i].number] = queries[i].name;
        else if (queries[i].type == "del")
            all_numbers[queries[i].number] = "a";
        else if (queries[i].type == "find"){
            if (all_numbers[queries[i].number]=="a"){
                    cout << "not found\n";
                    }
            else{
                cout << all_numbers[queries[i].number] << "\n";
                }
            }

}

}
