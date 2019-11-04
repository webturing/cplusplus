#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool v[3][3]={0};
    queue<pair<int,int> > Q;
    Q.push(make_pair(0,0));
    v[0][0]=true;
    while(Q.size()){
        pair<int,int> p=Q.front();
        int x=p.first,y=p.second;
        if(x+1<3&&v[x+1][y]==false){Q.push(make_pair(x+1,y));v[x+1][y]=true;}
        if(y+1<3&&v[x][y+1]==false){Q.push(make_pair(x,y+1));v[x][y+1]=true;}
        cout<<p.first<<" "<<p.second<<endl;
        Q.pop();
    }
    return 0;
}
