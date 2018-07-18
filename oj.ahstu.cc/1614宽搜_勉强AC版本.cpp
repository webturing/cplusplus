#include <bits/stdc++.h>

using namespace std;
string init;
string target;
queue<pair<string, int> > Q;
set<string> history;
int success[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int bfs() {
    while (Q.size()) {
        if (Q.front().first == target) {
            return Q.front().second;
        }
        string str = Q.front().first;
        int pos = str.find('.');
        int x = pos / 3;
        int y = pos % 3;
        for (int i = 0; i < 4; i++) {
            int x0 = x + success[i][0];
            int y0 = y + success[i][1];
            if (x0 < 0 || y0 < 0 || x0 > 2 || y0 > 2)continue;
            string temp = str;
            swap(temp[pos], temp[3 * x0 + y0]);
            if (history.find(temp) != history.end())
                continue;
            Q.push(make_pair(temp, Q.front().second + 1));

        }
        history.insert(Q.front().first);
        Q.pop();
    }
    return -1;
}

int main() {
    ifstream cin("input.txt");
    cin >> init >> target;
    Q.push(make_pair(init, 0));
    history.insert(init);
    cout << bfs() << endl;
    return 0;
}