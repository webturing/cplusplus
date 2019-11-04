#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 100005;
    //cin>>n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            //check n==i+(i+1)+...+j
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += k;
            }
            if (s == n) {
                cout << i << " " << j << endl;
            }
        }
    return 0;
}