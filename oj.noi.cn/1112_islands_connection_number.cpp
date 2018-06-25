#include <bits/stdc++.h>
using  namespace std;
int main(){
    int n,m;
    cin >> n>>m;
    set<pair<int ,int >>ones;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x; cin >>x;
            if(x){
                ones.insert(make_pair(i,j));
            }
        }
    }
    int sum = 0;
    while(ones.size() > 0){
        pair<int ,int > head = *ones.begin();
        ones.erase(ones.begin());
        queue<pair<int ,int >>q;
        q.push(head);
        while (q.size()>0){
            head = q.front();
            q.pop();
            int x = head.first, y = head.second;
            vector<pair<int ,int >>next{make_pair(x,y+1), make_pair(x,y-1),make_pair(x+1,y),make_pair(x-1,y)};
            for(auto temp : next){
                auto it = ones.find(temp);
                if (it != ones.end()){
                    q.push(temp);
                    ones.erase(it);
                }
            }
        }
        sum++;
    }
    cout << sum << endl;
    return  0;
}