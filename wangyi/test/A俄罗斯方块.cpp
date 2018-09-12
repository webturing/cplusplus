//
// Created by jal on 18-9-8.
//
#include<bits/stdc++.h>

using namespace std;
int a[1001] = {0};

int main() {
    int n, m;
    cin >> n >> m;
    int g = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    cout << *min_element(a + 1, a + n + 1) << endl;
}
