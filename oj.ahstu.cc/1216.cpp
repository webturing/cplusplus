#include <iostream>

using namespace std;

int A[7] = {100, 50, 20, 10, 5, 2, 1};

int main() {
    for (int n; cin >> n;)
        while (n)
            for (int i = 0; i < 7; i++)
                while (n >= A[i])
                    cout << A[i] << endl, n -= A[i];
    return 0;
}