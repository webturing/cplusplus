#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 3, 4, 5, 2, 6, 8, 7, 9};
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    nth_element(v.begin(), v.begin() + 5, v.end());

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}