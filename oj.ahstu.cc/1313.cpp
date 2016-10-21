#include<iostream>
using namespace std;

bool find7(int n) {
    for (; n > 0; n /= 10)
        if (n % 10 == 7)return true;
    return false;
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    for (int i = 7; i <= N; i++)
        if (i % 7 == 0 || find7(i))
            cout << i << endl;
    return 0;
}
