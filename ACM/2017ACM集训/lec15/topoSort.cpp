#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 10000 + 5;
vector<int> g[maxn];
int du[maxn], n, m, L[maxn];

bool toposort()
{
	memset(du, 0, sizeof(du));
	for (int i=0; i<n; i++)
		for (int j=0; j<g[i].size(); j++)
			du[g[i][j]]++;
	int tot = 0;
	priority_queue<int> Q;
	for (int i=0; i<n; i++)
		if (!du[i]) Q.push(i);//入度为0的点存入优先队列
	while (!Q.empty()) {
		int x = Q.top(); Q.pop();
		L[tot++] = x;//取出入度为0的点，并存入数组
		for (int j=0; j<g[x].size(); j++){
			int t = g[x][j];
			du[t]--;//相连的点入度依次减一
			if (!du[t])
				Q.push(t);//把入度为0的点放入优先队列
		}
	}
	if (tot == n)
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &n, &m))
	{
		for(int i=0;i<n;i++)
            g[i].clear();
		while (m--)
		{
			int N, M;
			scanf("%d%d", &N, &M);
			g[N-1].push_back(M-1);
		}
		int first = 0;
		if (toposort()) {
            for (int i=0; i<n; i++) {
                if (first)
                    printf(" ");
                first = 1;
                printf("%d", L[i]+1);
            }
            printf("\n");
        }
        else
            printf("-1\n");
	}
	return 0;
}