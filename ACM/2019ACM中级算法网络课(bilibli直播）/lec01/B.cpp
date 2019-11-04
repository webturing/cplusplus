#include<bits/stdc++.h>

using namespace std;

int main() {
//    bitset<32> b(65535<<8>>16);
//    cout<<b<<endl;
    int n = 16;
    cin >> n;
    if (n < 256)n += 256;//(1)
    // n=(n<<16)>>16;//舍去高16位 rand() [0,RAND_MAX)
    n = (n & ((1 << 16) - 1));
    n = n * n;
    n = (n << 8) >> 16;
    cout << n << endl;

    return 0;
}