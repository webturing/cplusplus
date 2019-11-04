#include <bits/stdc++.h>

using namespace std;
struct Medal {
    int gold;
    int silver;
    int bronze;
};

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<Medal> v(n);
    Medal all = {0, 0, 0};
    for (auto &e:v) {
        cin >> e.gold >> e.silver >> e.bronze;
        all.gold += e.gold;
        all.silver += e.silver;
        all.bronze += e.bronze;
    }
    cout << all.gold << " "
         << all.silver << " "
         << all.bronze << " "
         << all.gold + all.silver + all.bronze << endl;


    return 0;
}
