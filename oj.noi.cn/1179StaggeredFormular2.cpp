#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

LL factorial(int n) { return n ? factorial(n - 1) * n : 1LL; }

LL D(int n) {
    return n <= 1 ? 0 : (LL) (factorial(n) / exp(1) + 0.5);//这个公式由于e的精度不够，对D(20)计算错误
}

int main() {
    int n;
    cin >> n;
    cout << D(n) << endl;
    return 0;
}
