#include <bits/stdc++.h>

using namespace std;

int maxSumLinear(vector<int> a) {
    int n = a.size() - 1;
    int sum = 0;
    int b = 0;
    for (int i = 0; i <= n; i++) {
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (b > sum) sum = b;
    }
    return sum;
}

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i:a)cin >> i;
    cout << maxSumLinear(a) << endl;
    return EXIT_SUCCESS;

}