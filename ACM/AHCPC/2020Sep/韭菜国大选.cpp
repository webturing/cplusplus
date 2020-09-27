#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int L[N * 30], R[N * 30], fa[N * 30], dep[N * 30];
int root[N * 30];
namespace Persistant_Union_Set {
#define Mid ((l+r)>>1)
#define lson L[rt],l,Mid
#define rson R[rt],Mid+1,r
    int cnt;
    int n, m;

    void build(int &rt, int l, int r) {
        rt = ++cnt;
        if (l == r) {
            fa[rt] = l;
            return;
        }
        build(lson);
        build(rson);
    }

    void merge(int last, int &rt, int l, int r, int pos, int Fa) {
        rt = ++cnt;
        L[rt] = L[last], R[rt] = R[last];
        if (l == r) {
            fa[rt] = Fa;
            dep[rt] = dep[last];
            return;
        }
        if (pos <= Mid)merge(L[last], lson, pos, Fa);
        else merge(R[last], rson, pos, Fa);
    }

    void update(int rt, int l, int r, int pos) {
        if (l == r) {
            dep[rt]++;
            return;
        }
        if (pos <= Mid)update(lson, pos);
        else update(rson, pos);
    }

    int query(int rt, int l, int r, int pos) {
        if (l == r)return rt;
        if (pos <= Mid)return query(lson, pos);
        else return query(rson, pos);
    }

    int find(int rt, int pos) {
        int now = query(rt, 1, n, pos);
        if (fa[now] == pos)return now;
        return find(rt, fa[now]);
    }

    void _union(int i, int x, int y) {
        static int posx, posy;
        root[i] = root[i - 1];
        posx = find(root[i], x);
        posy = find(root[i], y);
        if (fa[posx] != fa[posy]) {
            if (dep[posx] > dep[posy])swap(posx, posy);
            merge(root[i - 1], root[i], 1, n, fa[posx], fa[posy]);
            if (dep[posx] == dep[posy])update(root[i], 1, n, fa[posy]);
        }
    }

#undef Mid
#undef lson
#undef rson
}
using namespace Persistant_Union_Set;
char op[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    build(root[0], 1, n);
    for (int i = 1; i <= m; i++) {
        cin >> op + 1;
        root[i] = root[i - 1];
        if (op[1] == 'j') {
            int l, r;
            cin >> l >> r;
            _union(i, l, r);
        } else {
            int l = 1, r = i - 1, an = -1;
            int x, y;
            cin >> x >> y;
            while (l <= r) {
                int mid = l + r >> 1;
                if (find(root[mid], x) == find(root[mid], y))an = mid, r = mid - 1;
                else l = mid + 1;
            }
            if (an == -1)cout << "NO\n";
            else {
                cout << "YES " << an << '\n';
            }
        }

    }
    return 0;
}




/**
 * 题目名称：⾲菜国⼤选

题目描述
韭菜国的大选年到了，韭菜国议会将要选举出新的执政党。议会的选举制度是这样的：最一开始的时候每位议员都会各自组建独立党派，每个党派之间可以派出一位代表进行一对一谈判，如果谈判成功，那么两位议员分属的不同党派将合并成一个新的党派。最后包含议员数量最多的党派将获胜。作为韭约时报的记者，你将全程报道大选的过程。每一次的一对一谈判将是你报道的重点，此外，你还需要回复你热情的观众：选民们有时会对一些高人气的议员的活动很感兴趣，比如某两位议员现在是否属于同一党派，如果是，那么他们是什么时候成为同一阵营的。现在只考虑成功的谈判，并把每一次成功的谈判和观众的提问都视为一次事件，在大选中有若干次事件发生，对每次提问的事件，你都需要进行回答。
程序输入说明
第一行两个正整数 n和 m，分别表示韭菜国议会有 n 名议员，选举中发生了 m个事件。保证 n<=3*10^5, m <= 3 * 10^5。
接下来 m 行，每行一个字符串 s 和两个整数 a, b。保证 1<=a,b<=n。
如果 s的内容为`join`，则意味着本次事件是 a和 b 两位议员成功进行了谈判。
如果 s 的内容为`query`，则意味着你需要回答当前 a 和 b两位议员是否属于同一党派。
程序输出说明
对于每一次询问的事件，你都需要进行回答，每次回答占一行，如果两位议员不是同一阵营，输出NO；反之输出YES和一个数字 $i$，表示是在第 $i$ 次事件中两位议员成为了同一阵营。
程序输入样例
5 8
join 1 3
query 2 5
join 3 5
join 1 4
query 1 5
query 4 3
join 2 4
query 2 5
程序输出样例
NO
YES 3
YES 4
YES 7
 */

