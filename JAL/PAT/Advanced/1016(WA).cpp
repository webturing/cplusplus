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
struct ZJ{
    string name, time, state;
};
int main(){
    freopen("input.txt", "r", stdin);
    vector<int>v(24);
    for(auto &i: v){
        cin >> i;
    }
    vector<int>sum(25);
    partial_sum(v.begin(), v.end(), sum.begin()+1);
    int n = read();
    vector<ZJ>v2(n);
    for(auto &i: v2){
        cin >> i.name >> i.time >> i.state;
    }
    map<string, vector<ZJ> >M;
    for(auto i: v2){
        string key = i.name + " " + i.time.substr(0, 2);
        M[key].push_back(i);
    }
    for(auto i: M){
        cout << i.first << endl;
        vector<ZJ> val = i.second;
        sort(val.begin(), val.end(), [](ZJ z1, ZJ z2)->bool{
            return z1.time < z2.time;
        });
        double tot = 0;
        int x = -1;
//        while(val[x].state != "on-line")x++;
        for(int j = 0; j < val.size(); j++){
            if(val[j].state == "off-line"){
                if(x != -1){
                    int d1 = (val[x].time[3]-'0')*10 + val[x].time[4] - '0';
                    int d2 = (val[j].time[3]-'0')*10 + val[j].time[4] - '0';
                    int h1 = (val[x].time[6]-'0')*10 + val[x].time[7] - '0';
                    int h2 = (val[j].time[6]-'0')*10 + val[j].time[7] - '0';
                    int m1 = (val[x].time[9]-'0')*10 + val[x].time[10] - '0';
                    int m2 = (val[j].time[9]-'0')*10 + val[j].time[10] - '0';
                    double diffCent = 60 * (d2 - d1) * sum.back() + 60 * (sum[h2] - sum[h1]) - m1 * v[h1] + m2 * v[h2], diffMoney = diffCent / 100;
                    int diffTime = 24 * 60 * (d2 - d1) + 60 * (h2 - h1) - m1 + m2;
                    tot += diffMoney;
                    cout << val[x].time.substr(3) << " " << val[j].time.substr(3) << " " << diffTime;
                    cout << " $" <<fixed << setprecision(2) << diffMoney<< endl;
                }else{
                    x = -1;
                }
            }else{
                x = j;
            }
        }
        cout << "Total amount: $" <<fixed << setprecision(2) << tot << endl;
    }
}