#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <vector<int>> v;
    for (int j = 0; j < n; j++) {
        vector<int> x(n);
        for (int i = 0; i < n; i++)cin >> x[i];
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }

    return 0;
}