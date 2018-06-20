#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    map<int, string> price;
    price[1] = "price=3.0";
    price[2] = "price=2.5";
    price[3] = "price=4.1";
    price[4] = "price=10.2";
    cout << "[1] apples\n"
            "[2] pears\n"
            "[3] oranges\n"
            "[4] grapes\n"
            "[0] Exit" << endl;
    int user;
    cin >> user;
    if (user == 0) {
        return 0;
    } else if (1 <= user && user <= 4) {
        cout << price[user] << endl;
    } else if (user != 0) {
        cout << "price=0" << endl;
    }

    return 0;
}