//
// Created by jal on 18-7-7.
//

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    deque<P>v(n);
    for(auto &i:v){
        cin >> i.first >> i.second;
    }
    int m;
    cin >> m;
    while(m--){
        string op;
        int x,y;
        cin >> op;
        if(op[0] == 'E'){
            int left,right;
            cin >> left >> right;
            double weight = accumulate(v.begin()+left-1, v.begin()+right,0,[](int a,P b)-> int{return a + b.first;});
            double volumn = accumulate(v.begin()+left-1, v.begin()+right,0,[](int a,P b)-> int{return a + b.second;});
            cout << fixed << setprecision(3)<< weight/volumn << endl;
        }
        else if(op[0] == 'I'){
            int index,x,y;
            cin >> index >> x >> y;
            if(index == 0){
                v.push_front(make_pair(x,y));
            }else if(index == n){
                v.push_back(make_pair(x,y));
            }
            else
                v.insert(v.begin()+index, make_pair(x,y));
        }
        else if(op[0] == 'D'){
            int z;
            cin >> z;
            v.erase(v.begin() + z - 1);
        }
    }
}