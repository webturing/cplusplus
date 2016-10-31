#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> p(1000, 1);
    p[0] = p[1] = 0;
    for (unsigned i = 2; i * i <= p.size(); i++)
        if (p[i])
            for (int j = i * i; j < p.size(); j += i)p[j] = 0;
    for (int M; cin >> M;)
        for (int N, s, t; cin >> N;) {
            for (s = 0; N-- && cin >> t;)
                if (p[t])s += t;
            cout << s << endl;
        }

    return 0;
}
