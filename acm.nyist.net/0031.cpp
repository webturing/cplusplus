#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> v(5);
    for (int i = 0; i < v.size(); i++)cin >> v[i];
    sort(v.begin(), v.end());
    cout << *v.begin() << " " << *v.rbegin() << endl;
    return 0;
}
