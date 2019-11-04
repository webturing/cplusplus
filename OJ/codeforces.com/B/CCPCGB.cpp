#include<bits/stdc++.h>

using namespace std;

bool foo(int n, int &p, int &q) {
    int r = sqrt(n);
    if (r < 5)return false;
    for (p = r; p >= 1; p--) {
        q = n / p;
        if (n % p == 0 and n % q == 0)
            break;
    }
    return p >= 5 and q >= 5;
}

vector<string> V = {"aeiou", "eioua", "iouae", "ouaei", "uaeio"};

int main() {
    int k;
    cin >> k;
    int p, q;
    if (not foo(k, p, q)) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < p; i++) {
            for (int b = 0; b < q / 5; b++) {
                cout << V[i % 5];
            }
            cout << V[i % 5].substr(0, q % 5);
        }
        cout<<endl;
    }
    return 0;
}