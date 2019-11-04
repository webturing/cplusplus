#include<bits/stdc++.h>

using namespace std;

//O(n^3)=>O(n^2)=>O(nlogn)=>O(n) =>O(sqrt(n)
int main() {//O(n^2)
    int n = 1000000005;
    cin >> n;
    int m = 2 * n;
    for (int p = sqrt(m); p >= 1; p--) {
        if (m % p == 0) {
            int q = m / p;//q是较大的因子
            // j-i+1=p  i+j=q => i=(q-p+1)/2 j=(p+q-1)/2
            int i = (q - p + 1) / 2;
            int j = (q + p - 1) / 2;
            if (j > i and (p + q) % 2 != 0)
                cout << i << " " << j << endl;
        }
    }
    return 0;
}