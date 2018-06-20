#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 50;
vector<bool> primes(maxn, true);

void sieve() {
    primes[0] = primes[1] = false;
    for (int i = 2; i * i < primes.size(); i++)
        if (primes[i])
            for (int j = i * i; j < primes.size(); j += i)
                primes[j] = false;
}


int main(int argc, char const *argv[]) {
    sieve();
    int n;
    cin >> n;
    bool find = false;
    for (int i = 3; i + 2 <= n; i += 2) {
        if (primes[i] && primes[i + 2]) {
            find = true;
            cout << i << " " << i + 2 << endl;
        }
    }
    if (!find)
        cout << "empty" << endl;
    return 0;
}