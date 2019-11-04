#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > AA(vector<vector<int> > A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > B(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = A[n - 1 - j][i];
    return B;
}

vector<vector<int> > BB(vector<vector<int> > A) {
    return AA(AA(AA(A)));
}

vector<vector<int> > CC(vector<vector<int> > A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > B(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            B[i][j] = A[i][m - 1 - j];
    return B;
}

vector<vector<int> > DD(vector<vector<int> > A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > B(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            B[i][j] = A[n - 1 - i][j];
    return B;
}

void disp(vector<vector<int> > B) {
    int m = B.size();
    int n = B[0].size();
    for (int i = 0; i < m; i++) {
        cout << B[i][0];
        for (int j = 1; j < n; j++)
            cout << " " << B[i][j];
        cout << endl;
    }
    //  cout << "---------------" << endl;
}

void copy(vector<vector<int> > from, vector<vector<int> > &to) {
    int r = from.size();
    int c = from[0].size();
    to.resize(r);
    for (int i = 0; i < r; i++)
        to[i].resize(c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            to[i][j] = from[i][j];
}

int main(int argc, char const *argv[]) {
    //ifstream cin("input.txt");
    int n = 3, m = 5;
    cin >> n >> m;
    vector<vector<int> > A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    string op;
    cin >> op;

    for (auto c:op) {
        switch (c) {
            case 'A':
                copy(AA(A), A);
                break;
            case 'B':
                copy(BB(A), A);
                break;
            case 'C':
                copy(CC(A), A);
                break;
            case 'D':
                copy(DD(A), A);
                break;
        }
    }
    disp(A);
    return 0;

}