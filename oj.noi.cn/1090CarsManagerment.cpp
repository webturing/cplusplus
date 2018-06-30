#include<bits/stdc++.h>

using namespace std;

struct Car {
    int id;
    string S;
    int V;
    int W;
    int t;
    string name;
    string phone;

    friend istream &operator>>(istream &is, Car &car) {
        is >> car.S >> car.V >> car.W >> car.t;
        if (car.t == 0)is >> car.name;
        else is >> car.phone;
        return is;
    }
};

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<Car> cars(n);
    int id = 0;
    for (auto &car:cars) {
        cin >> car;
        car.id = ++id;
    }
    int q;
    cin >> q;
    while (q--) {

        int op;
        cin >> op;
        if (op == 1) {
            int id;
            cin >> id;
            cout << cars[id - 1].S << endl;
        } else if (op == 2) {
            string s;
            cin >> s;
            for (auto car:cars) {
                if (car.S == s) {
                    if (car.t == 0)
                        cout << car.name << endl;
                    else
                        cout << car.phone << endl;
                }
            }
        } else {
            int k;
            cin >> k;
            cout << count_if(cars.begin(), cars.end(), [k](Car ca) -> bool { return 1.0 * ca.V / ca.W >= k; }) << endl;
        }
    }

    return 0;
}