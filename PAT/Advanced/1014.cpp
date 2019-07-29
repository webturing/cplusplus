#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
template <typename T = int>
void OO(vector<T>v, string s=""){
    cerr<<s <<":"<< endl;
    for(auto i: v){
        cerr << i << ' ';
    }
    cerr << endl;
}
typedef unsigned long long ll;
int main(){
    freopen("input.txt", "r", stdin);
    int n = read(), m = read(), k = read(), q = read();
    vector<int>v(k);//所需时长
    for(int i = 0; i < k; i++){
        v[i] = read();
    }
    vector<list<int>>D(n);//模拟窗口
    vector<int>leave(k, INT_MAX);//离开的时间
    int t = min(n*m, k);
    for(int i = 0; i < t; i++){
        auto p = D.begin();
        for(auto j = D.begin()+1; j != D.end(); j++){
            if((*j).size() < m and (*j).size() < (*p).size()) p = j;
        }
        if((*p).size() <= 0){
            leave[i] = v[i];
        }else{
            if(leave[(*p).back()] < 540){
                leave[i] = v[i] + leave[(*p).back()];
            }else{
                leave[i] = INT_MAX;
            }
        }
        (*p).push_back(i);
    }
    while(t < k){
        auto p = D.begin();
        for(auto j = D.begin()+1; j != D.end(); j++){
            if(leave[(*j).front()] < leave[(*p).front()]) p = j;
        }
        if(leave[(*p).back()] < 540){
            leave[t] = v[t] + leave[(*p).back()];
        }else{
            leave[t] = INT_MAX;
        }
        (*p).push_back(t);
        (*p).pop_front();
        t++;
    }
    for(int i = 0; i < q; i++){
        int r = leave[read()-1];
        if(r >= INT_MAX){
            cout << "Sorry" << endl;
        }else{
            cout << setw(2) << setfill('0') << r/60+8 << ":" << setw(2) << setfill('0') << r % 60 << endl;
        }
    }
}