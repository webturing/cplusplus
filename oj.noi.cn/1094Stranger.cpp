#include <bits/stdc++.h>

using namespace std;

const int MOD = 12345;

int add(int a, int b) {
    return a * b + b * a;
}

int substract(int a, int b) {
    return a + b + a * b;
}

int multiply(int a, int b) {
    return a * a + b * b;
}

int divide(int a, int b) {
    return b - a + b * a;
}


int main(int argc, char const *argv[]) {
    ifstream cin("input.txt");
    int T;
    cin >> T;
    string op;
    int b;
    int a = 0;
    while (T-- && cin >> op >> b) {
        if (op == "+") {
            a = add(a, b);
        } else if (op == "-") {
            a = substract(a, b);
        } else if (op == "*") {
            a = multiply(a, b);
        } else if (op == "/") {
            a = divide(a, b);
        }
        a %= MOD;
        cout << a << endl;
    }
    return 0;
}