#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        while (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &e : A) cin >> e;

    int pos = partition(A, A.size(), A.size() - 1);
    cout << A[0];
    for (int i = 1; i < pos; i++) cout << " " << A[i];
    cout << " [" << A[pos] << "]";
    for (int i = pos; i < A.size() - 1; i++) cout << " " << A[i];
    cout << endl;
    return 0;
}
