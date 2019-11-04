#include <bits/stdc++.h>

using namespace std;

const int TOTAL = (1 + 13) * 13;
const int N = 26;

int main(void) {
    int sum = 0;
    vector<int> cards(N);
    for (i = 1; i < N; i++) {
        cin >> cards[i];
        sum += cards[i];
    }

    cout << TOTAL - sum << endl;

    return 0;
}