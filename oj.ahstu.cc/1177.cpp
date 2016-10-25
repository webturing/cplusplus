#include<iostream>
#include<vector>

using  namespace std;

int main(int argc, char const *argv[]) {
    for (int n; cin >> n;) {
        vector<int> v(1, 1);
        for (int i = 2; i <= n; i++) {
            int sc = 0;
            for (int j = 0; j < v.size(); j++) {
                sc = sc + v[j] * i;
                v[j] = sc % 10;
                sc /= 10;
            }
            for (; sc; sc /= 10)
                v.push_back(sc % 10);
        }
        for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
            cout << *it;
        cout << endl;
    }
    return 0;
}