#include<bits/stdc++.h>
using namespace std;

#define Abigail inline void
typedef long long LL;

const int N=100000;
const LL INF=(1LL<<60)-1;

struct side{
    int y,next;
}e[N*2+9];
int lin[N+9],top;

void ins(int x,int y){
    e[++top].y=y;
    e[top].next=lin[x];
    lin[x]=top;
}

int siz[N+9],n,leaf[N+9],b[N+9];
LL ans[N+9],mn=INF;
char c[N+9];

void dfs1(int k,int fa){
    for (int i=lin[k];i;i=e[i].next)
        if (e[i].y^fa){
            dfs1(e[i].y,k);
            leaf[k]+=leaf[e[i].y];
        }
    if (k^1) ans[1]+=(LL)leaf[k]*siz[k];
}

void dfs2(int k,int fa){
    ans[k]=ans[fa]+3LL*(leaf[1]-leaf[k])-(LL)leaf[k]*siz[k];
    for (int i=lin[k];i;i=e[i].next)
        if (e[i].y^fa) dfs2(e[i].y,k);
}

Abigail into(){
    scanf("%d",&n);
    int m,y;
    for (int i=1;i<=n;++i){
        scanf("%s%d",c+1,&m);
        siz[i]=strlen(c+1);
        if (m==0) leaf[i]=b[i]=1;
        else{
            ++siz[i];
            for (int j=1;j<=m;++j){
                scanf("%d",&y);
                ins(i,y);ins(y,i);
            }
        }
    }
}

Abigail work(){
    dfs1(1,0);
    for (int i=lin[1];i;i=e[i].next)
        dfs2(e[i].y,1);
    for (int i=1;i<=n;++i)
        if (!b[i]) mn=min(mn,ans[i]);
}

Abigail outo(){
    printf("%lld\n",mn);
}

int main(){
    into();
    work();
    outo();
    return 0;
}