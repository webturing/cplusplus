#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    while (n) {
        int yu = n & 1;
        int shang = n >> 1;
        cout << "shang:" << shang << " yu:" << yu << endl;
        n = shang;
    }

    return 0;
}
