#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
T read(){
    T x;
    cin >> x;
    return x;
}

int main() {
//    ifstream fin("input.txt");
    int n = read(), b = read();
    vector<int>v;
    while(n){
        v.push_back(n%b);
        n /= b;
    }
    vector<int>v2(v.rbegin(), v.rend());
    if(v == v2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    cout << v2[0];
    for(int i = 1; i < v2.size(); i++){
        cout << ' ' << v2[i];
    }
    return 0;
}
