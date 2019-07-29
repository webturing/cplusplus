#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
typedef unsigned long long ll;
struct ZJ{
    string name;
    vector<double>score, rank;
    ZJ(){
        score.resize(4);
        rank.resize(4);
    }
    bool operator==(const ZJ& that)const{
        return name == that.name;
    }
};
int main(){
    freopen("input.txt", "r", stdin);
    int n = read(), m = read();
    vector<ZJ>v(n);
    for(auto& i: v){
        cin >> i.name >> i.score[1] >> i.score[2] >> i.score[3];
        i.score[0] = (i.score[1] + i.score[2] + i.score[3])/3.0;
    }
    for(int i = 0; i < 4; i++){
        sort(v.begin(), v.end(), [i](ZJ a, ZJ b)->bool{
            return a.score[i] > b.score[i];
        });
        v[0].rank[i] = 1;
        for(int j = 1; j < n; j++){
            if(v[j].score[i] == v[j-1].score[i]){
                v[j].rank[i] = v[j-1].rank[i];
            }else{
                v[j].rank[i] = j+1;
            }
        }
    }
    map<string, ZJ>M;
    for(auto i: v){
        M[i.name] = i;
    }
    string type = "ACME";
    for(int i = 0; i < m; i++){
        string s = read<string>();
        if(M.find(s) != M.end()){
            auto p = min_element(M[s].rank.begin(), M[s].rank.end());
            cout << *p << ' ' << type[p-M[s].rank.begin()] << endl;
        }else{
            cout << "N/A" << endl;
        }
    }
}