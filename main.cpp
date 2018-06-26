#include <bits/stdc++.h>
using namespace std;
int solution(vector<int>v, int left, int right){
    int ret = 0;
    for(int i = left; i < right; i++){
        switch (i){
            case 0:ret += 5;
                break;
            case 2:ret += 11;
                break;
            case 3:ret += 7;
                break;
            case 4:ret += -1;
        }
    }
    ret += v[right];
    if(right == 2)
    return ret;
}
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x != 1){
            v.push_back(x);
        }
    }
    int m = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){
            int sum = solution(v,i,j);
            m = max(sum, m);
        }
    }
    cout << m << endl;
}