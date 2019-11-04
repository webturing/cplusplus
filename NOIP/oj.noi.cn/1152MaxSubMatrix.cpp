#include<bits/stdc++.h>

using namespace std;
#define LOCAL

static int maxSumLinear(vector<int> &a) {
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

static int maxSum2(vector<vector<int>> a) {
    int sum = 0;
    int m = a.size(), n = a[0].size();
    vector<int> b(n, 0);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) b[k] = 0;
        for (int j = i; j < m; j++) {
            for (int k = 0; k < n; k++) b[k] += a[j][k];
            int max = maxSumLinear(b);
            if (max > sum) sum = max;
        }
    }
    return sum;
}

int main() {
#ifdef LOCAL
    long long start = clock();
#endif
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<vector<int>> sum(a);


    cout << maxSum2(a) << endl;
#ifdef LOCAL
    long long end = clock();
    cerr << end - start << endl;
#endif

    return 0;
}
