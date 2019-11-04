#include<bits/stdc++.h>

using namespace std;
namespace COLOR {
    const int RED = 0, YELLOW = 1, BLUE = 2, GREEN = 3, PURPLE = 4;
    const vector<pair<int, int> > VALUE{make_pair(5, 0), make_pair(0, 0), make_pair(10, 1), make_pair(7, 0),
                                        make_pair(1, -2)};
};

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> candies(n);
    for (auto &candy:candies)cin >> candy;
    int gmax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int kmax = 0;
            int sc = 0;
            for (int k = i; k <= j; k++) {
                kmax += COLOR::VALUE[candies[k]].first + sc;
                sc = COLOR::VALUE[candies[k]].second;
            }
            if (kmax > gmax)
                gmax = kmax;
        }

    }
    cout << gmax << endl;

    return 0;
}