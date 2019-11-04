#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> Point;
typedef pair<Point, Point> Pair;

bool cmp(Point a, Point b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
   // ifstream cin("input.txt");
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;
    vector<Pair> pairs(d);
    map<int, int> horizontals, verticals;
    for (auto &p:pairs) {
        cin >> p.first.first >> p.first.second >> p.second.first >> p.second.second;
        if (p.first > p.second)
            swap(p.first, p.second);
        if (p.first.first == p.second.first) {
            verticals[p.first.second]++;
        } else {
            horizontals[p.first.first]++;
        }
    }
    vector<Point> hh(horizontals.begin(), horizontals.end());
    vector<Point> vv(verticals.begin(), verticals.end());
    sort(hh.begin(), hh.end(), cmp);
    sort(vv.begin(), vv.end(), cmp);
    if (hh.size() > k)hh.resize(k);
    if (vv.size() > l)vv.resize(l);
    sort(hh.begin(), hh.end());
    sort(vv.begin(), vv.end());
    for (auto h:hh)cout << h.first << " ";
    cout << endl;
    for (auto v:vv)cout << v.first << " ";
    cout << endl;


    return 0;
}