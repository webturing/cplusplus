//
// Created by jal on 18-7-18.
//

#include <bits/stdc++.h>

using namespace std;
int f[101];
int book[100 + 1];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
        f[root_x] = root_y;
    }
}

int main() {
    ifstream cin("input.txt");
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    int x, y;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        merge(x, y);
    }
    int family_number = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            family_number++;
        }
    }

    for (int i = 1; i <= n; i++) {
        find(i);
    }
    memset(book, 0, sizeof(book));
    for (int i = 1; i <= n; i++) {
        book[f[i]]++;
    }
    cout << family_number << " " << *max_element(book + 1, book + n + 1) << endl;
}