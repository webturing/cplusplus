#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    auto result = minmax_element(v.begin(), v.end());
    cout << *result.first << " " << *result.second << endl;

    return 0;
}