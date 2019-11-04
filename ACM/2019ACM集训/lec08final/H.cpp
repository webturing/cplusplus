#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f3f;
const int MAXN = 1e3 + 10;
int Next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char G[MAXN][MAXN];
int level[MAXN][MAXN];
int n;
int res1, res2;

void Bfs(int i, int j)
{
    int tmp1 = 0, tmp2 = 0;
    queue<pair<int, int> > que;
    que.push(make_pair(i, j));
    G[i][j] = '.';
    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        tmp1++, tmp2 += level[x][y];
        for (int i = 0;i < 4;i++)
        {
            int tx = x + Next[i][0];
            int ty = y + Next[i][1];
            if (tx < 1 || tx > n || ty < 1 || ty > n)
                continue;
            if (G[tx][ty] == '.')
                continue;
            que.push(make_pair(tx, ty));
            G[tx][ty] = '.';
        }
    }
    //cout << tmp1 << ' ' << tmp2 << endl;
    if (tmp1 > res1)
    {
        res1 = tmp1;
        res2 = tmp2;
    }
    else if (tmp1 == res1)
    {
        //cout << 1 << endl;
        if (tmp2 < res2)
        {
            res2 = tmp2;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            cin >> G[i][j];
    memset(level, 0, sizeof(level));
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (G[i][j] == '.')
                continue;
            for (int k = 0;k < 4;k++)
            {
                int tx = i+Next[k][0];
                int ty = j+Next[k][1];
                if (tx < 1 || tx > n || ty < 1 || ty > n)
                {
                    level[i][j]++;
                    continue;
                }
                if (G[tx][ty] == '.')
                    level[i][j]++;
            }
        }
    }
    /*
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            cout << level[i][j] << ' ';
        cout << endl;
    }
    */
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (G[i][j] == '#')
                Bfs(i, j);
        }
    }
    cout << res1 << ' ' << res2 << endl;

    return 0;
}