#include <bits/stdc++.h>

using namespace std;
#define  LOCAL

int main() {
#ifdef LOCAL
    ifstream cin("input.txt");
    long long start = clock();
#endif
    int i, j, k;
    int lenA, lenB, len, maxLen;
    char A[256], B[256];
    while (cin >> A >> B) {
        maxLen = 0;
        lenA = (int) strlen(A);
        lenB = (int) strlen(B);

        for (i = 0; i < lenA; i++) {
            for (j = 0; j < lenB; j++) {
                len = 0;
                for (k = 0; k < lenA + lenB; k++) {
                    if (A[(i + k) % lenA] == B[(j + k) % lenB]) {
                        len++;
                    } else {
                        maxLen = max(len, maxLen);
                        len = 0;
                    }
                }

            }
        }

        cout << maxLen << endl;
    }

#ifdef LOCAL
    long long end = clock();
    cerr << end - start << endl;
#endif
}
