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
        for (int N, A, B; M-- && cin >> N;) {
            for (A = N; !p[A]; ++A);
            for (B = N; !p[B]; --B);
            if (A - N < N - B)
                cout << A << " " << A - N << endl;
            else
                cout << B << " " << N - B << endl;
        }

    return 0;
}
