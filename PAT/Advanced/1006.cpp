#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
struct Time{
    int h, m, s;
    bool operator<(const Time&t)const {
        if(h != t.h){
            return h < t.h;
        }
        if(m != t.m){
            return m < t.m;
        }
        return s < t.s;
    }
};
bool cmp(string s1, string s2){
    transform(s1.begin(), s1.end(), s1.begin(), [](char c)->char{
        return c == ':'?' ':c;
    });
    transform(s2.begin(), s2.end(), s2.begin(), [](char c)->char{
        return c == ':'?' ':c;
    });
    istringstream iss(s1+" " + s2);
    Time t1, t2;
    iss >> t1.h >> t1.m >> t1.s;
    iss >> t2.h >> t2.m >> t2.s;
    return t1 < t2;

}
struct Node{
    string s, s1, s2;
};
int main(){
    int n = read();
    vector<Node>v(n);
    for(auto &i: v){
        cin >> i.s >> i.s1 >> i.s2;
    }
    sort(v.begin(), v.end(), [](Node p, Node q)->bool{
        return cmp(p.s1, q.s1);
    });
    cout << v.front().s << ' ';
    sort(v.begin(), v.end(), [](Node p, Node q)->bool{
        return cmp(p.s2, q.s2);
    });
    cout << v.back().s << endl;
}