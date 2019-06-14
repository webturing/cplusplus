#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 3, 5, 8, 7, 9, 4};

    cout << "first odd is " << *find_if(v.begin(), v.end(), [](int x) {
        return x & 1;
    }) << endl;


    cout << "first even is " << *find_if_not(v.begin(), v.end(), [](int x) {
        return x & 1;
    }) << endl;

    return 0;
}