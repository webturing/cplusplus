//
// Created by jal on 2019-05-22.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<char, list<int> >mp1, mp2;
    vector<pair<int, int> >v;
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 0; i < n; i++){
        mp1[s1[i]].push_back(i+1);
        mp2[s2[i]].push_back(i+1);
    }
    for(int i = 'a'; i <= 'z'; i++){
        while(mp1[i].size() > 0 && mp2[i].size() > 0){
            v.push_back({mp1[i].front(), mp2[i].front()});
            mp1[i].pop_front();
            mp2[i].pop_front();
        }
        while(mp1[i].size() > 0 && mp2['?'].size() > 0){
            v.push_back({mp1[i].front(), mp2['?'].front()});
            mp1[i].pop_front();
            mp2['?'].pop_front();
        }
        while(mp1['?'].size() > 0 && mp2[i].size() > 0){
            v.push_back({mp1['?'].front(), mp2[i].front()});
            mp1['?'].pop_front();
            mp2[i].pop_front();
        }
    }
    while(mp1['?'].size() > 0 && mp2['?'].size() > 0){
        v.push_back({mp1['?'].front(), mp2['?'].front()});
        mp1['?'].pop_front();
        mp2['?'].pop_front();
    }
    cout << v.size() << endl;
    for(auto i : v){
        cout << i.first << " " << i.second << endl;
    }
}