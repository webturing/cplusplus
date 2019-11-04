#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 3, 5, 7, 9};

    cout << all_of(v.begin(), v.end(), [](int x) -> bool {
        return x & 1;
    }) << endl;

    for_each(v.begin(), v.end(), [](int &x) -> int {
        ++x;
    });


    cout << none_of(v.begin(), v.end(), [](int x) -> bool {
        return x & 1;
    }) << endl;


    cout << any_of(v.begin(), v.end(), [](int x) -> bool {
        return x % 3 == 0;
    }) << endl;


    return 0;
}