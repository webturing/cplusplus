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
    int index[3];
    double res = 0;
};
int main(){
    freopen("input.txt", "r", stdin);
    vector<double>v(9);
    for(auto &i: v){
        cin >> i;
    }
    ZJ best;
    for(int i = 0; i < 3; i++){
        for(int j = 3; j < 6; j++){
            for(int k = 6; k < 9; k++){
                double t = (v[i] * v[j] * v[k] * 0.65 - 1) * 2;
                if(t > best.res){
                    best.index[0] = i, best.index[1] = j, best.index[2] = k;
                    best.res = t;
                }
            }
        }
    }
    string s = "WTL";
    cout << s[best.index[0]] << ' ' << s[best.index[1]%3] << ' ' << s[best.index[2]%3] << ' ' << fixed << setprecision(2) << best.res << endl;
}