#include<iostream>

bool find7(int i);

using namespace std;

int main() {
    for (int n; cin >> n;) {
        int tot = 0;
        for (int i = 7; i <= n; i++)
            if (find7(i) || i % 7 == 0) {
                ++tot;
            }

        cout << tot << endl;

    }
    return 0;
}

bool find7(int n) {
    while (n) {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}