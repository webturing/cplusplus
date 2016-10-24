#include <iostream>
#include<vector>

using namespace std;

int main() {
    for (int n; cin >> n;) {
        vector<vector<int> > M;
        for (int i = 0; i < n; i++) {
            vector<int> m(n);
            for (int j = 0; j < n; j++)
                cin >> m[j];
            M.push_back(m);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j || i + j == n - 1)sum += M[i][j];
        cout << sum << endl;
    }
    return 0;
}