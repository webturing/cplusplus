//
// Created by jal on 18-7-18.
//

#include <bits/stdc++.h>

using namespace std;
string s, e;

struct ZJ {
    string str;
    int step;

    ZJ(string str, int step) : str(str), step(step) {}
};

int nex[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
set<string> st;

int main() {
    ifstream cin("input.txt");
    cin >> s >> e;
    queue<ZJ> q;
    ZJ first(s, 0);
    q.push(first);
    st.insert(s);
    int best = -1;
    while (!q.empty()) {
        ZJ head = q.front();
        q.pop();
        string cur = head.str;
        if (cur == e) {
            best = head.step;
            break;
        }
        int pos = cur.find('.');
        int x = pos / 3;
        int y = pos % 3;

        for (int k = 0; k < 4; k++) {
            int tx = x + nex[k][0];
            int ty = y + nex[k][1];
            if (tx < 0 || ty < 0 || tx > 2 || ty > 2)continue;
            int next_pos = tx * 3 + ty;
            swap(cur[pos], cur[next_pos]);
            if (st.find(cur) == st.end()) {
                st.insert(cur);
                q.push(ZJ(cur, head.step + 1));
            }
            swap(cur[pos], cur[next_pos]);
        }
    }
    cout << best << endl;
}