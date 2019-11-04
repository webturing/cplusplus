#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<LL> a(n, 0);

    for (auto &e:a)cin >> e;
    vector<LL> b(n + 1, 0);
    partial_sum(a.begin(), a.end(), b.begin() + 1);

    map<int, vector<pair<int, int> >> M;
    for (int i = 0; i <=n; i++)
        for (int j = i+1; j <= n; j++) {
            M[b[j] - b[i ]].push_back(make_pair(i + 1, j));

        }
    for (auto &p:M) {
        //删除有交叉的区间,
        sort(p.second.begin(), p.second.end(), [](pair<int, int> pa, pair<int, int> pb) -> bool {
            if (pb.second != pa.second)return pa.second < pb.second;
            return pa.first < pb.first;
        });
        vector<pair<int, int>> w;
        int start = 0;
        for (auto pp:p.second) {
            if (pp.first >start) {
                w.push_back(pp);
                start = pp.second;
            }
        }
        p.second.resize(w.size());
        sort(w.begin(),w.end(),[](pair<int, int> pa, pair<int, int> pb) -> bool {return pa.first<pb.first;});
        copy(w.begin(), w.end(), p.second.begin());
    }
    int gmax = 0;
    for (auto p:M)
        if (p.second.size() > M[gmax].size()) {
            gmax = p.first;
        }
    cout << M[gmax].size() << endl;
    for (auto p:M[gmax])
        cout << p.first << " " << p.second << endl;
    return 0;
}
