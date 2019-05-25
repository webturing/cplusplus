#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    vector<string> P = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    queue<int> Q;
    int n;
    cin >> n;
    int j = 0;
    for (int i = 0; i < 5; i++) Q.push(i);
    while (--n) {
        int x = Q.front();
        Q.pop();
        Q.push(x);
        Q.push(x);
    }
    cout << P[Q.front()] << endl;
    return 0;
}