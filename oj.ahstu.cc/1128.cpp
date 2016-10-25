#include <iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<bool> prime(10001, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < prime.size(); i++)
        if (prime[i])
            for (int j = i * i; j < prime.size(); j += i)
                prime[j] = false;
    for (int N; cin >> N;)
        cout << "NY"[prime[N]] << endl;
    return 0;
}