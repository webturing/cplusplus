#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
typedef unsigned long long ll;
ll getRadix(string s, int radix){
    ll ret = 0;
    for(int i = 0; i < s.size(); i++){
        int t;
        if(s[i] >= 'a'){
            t = s[i] - 'a' + 10;
        }else{
            t = s[i] - '0';
        }
        if(t >= radix)return LONG_LONG_MAX;
        ret = 1LL*ret * radix + t;
    }
    return ret;
}
int main(){
    freopen("input.txt", "r", stdin);
    string n1 = read<string>(), n2 = read<string>();
    int tag = read(), radix = read();
    if(tag == 2) {
        swap(n1, n2);
    }
    ll x = getRadix(n1, radix);
    ll min_radix = 0;
    for(auto i: n2){
        if(isdigit(i)){
            if(i - '0' > min_radix)
            min_radix = i - '0' + 1;
        }else{
            if(i - 'a' + 10 > min_radix)
            min_radix = i - 'a' + 10 + 1;
        }
    }
    ll left = min_radix, right = max(x, min_radix);
    ll best = 0;
    while(left <= right){
        ll mid = (left + right ) >> 1;
        ll t = getRadix(n2, mid);
        if(t < 0 || t > x){
            right = mid - 1;
        }else{
            left = mid + 1;
            if(t == x){
                best = mid;
            }
        }
    }
    if(best){
        cout << best << endl;
    }else
    cout << "Impossible" << endl;

}