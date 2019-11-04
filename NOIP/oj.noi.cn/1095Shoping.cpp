#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define LOCAL

struct Item {
    int id;
    int v;
    int m;

    bool operator<(const Item &that) const {
        if (v != that.v)
            return v > that.v;
        return m < that.m;
    }
};

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
    assert(cin);
    LL start = clock();
#endif
    int n;
    cin >> n;
    vector<Item> a(n);
    int no = 1;
    for (auto &i:a) {
        cin >> i.v >> i.m;
        i.id = no++;
    }
    sort(a.begin(), a.end());
    for (auto i:a)
        cout << i.id << " ";
    cout << endl;
#ifdef LOCAL
    LL
            end = clock();
    printf("%.3f\n", (double) (end - start) / CLOCKS_PER_SEC);
#endif
    return 0;
}

