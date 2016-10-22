#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int N, n, m, s, i;
    for (cin >> N; N-- && cin >> n >> m;) {
        for (s = 0, i = 1; i <= n; i++)
            s += i % m;
        cout << s << endl;
    }
    return 0;
}