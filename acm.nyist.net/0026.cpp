#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> p(1000000 + 50, 1);
    p[0] = p[1] = 0;
    for (unsigned i = 2; i * i <= p.size(); i++)
        if (p[i])
            for (int j = i * i; j < p.size(); j += i)p[j] = 0;
    for (int M; cin >> M;)
        for (int N; M-- && cin >> N;) {
            int tot = N < 3 ? 0 : 1;
            for (int i = 3; i + 2 <= N; i += 2)
                if (p[i] && p[i + 2])
                    tot++;
            cout << tot << endl;
        }

    return 0;
}
