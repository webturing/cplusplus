//
// Created by jal on 2019-05-21.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
//    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i:v) {
        cin >> i;
    }
    vector<int> sum(n + 1, 0);
    partial_sum(v.begin(), v.end(), sum.begin() + 1);
    map<int, vector<pair<int, int> > > mp;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            mp[sum[j] - sum[i - 1]].push_back({i, j});
        }
    }
    int max_block = 0;
    for (auto& p: mp) {
        if (p.second.size() == 0)continue;
        sort(p.second.begin(), p.second.end(),
             [](pair<int, int> pa, pair<int, int> pb) -> bool {
            if(pa.second != pb.second)
            return pa.second < pb.second;
            return pa.first < pb.first;
        });
        vector<pair<int, int> > block;
        int start = 0;
        for (int j = 0; j < p.second.size(); j++) {
            if (start < p.second[j].first) {
                block.push_back(p.second[j]);
                start = block.back().second;
            }
        }
        p.second = block;
        if (p.second.size() > max_block) {
            max_block = p.second.size();
        }
    }
    if(max_block ==0){
        cout << -1 << endl;
        return 0;
    }
    for (auto p: mp) {
        if (p.second.size() == max_block) {
            cout << max_block << endl;
            for (auto j : p.second) {
                cout << j.first << " " << j.second << endl;
            }
            break;
        }
    }
}