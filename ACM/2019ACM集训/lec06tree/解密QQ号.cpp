
//
// Created by jal on 18-9-2.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int>li = {6,3,1,7,5,8,9,2,4};
    vector<int>v;
    while(li.size() > 0){
        int t = li.front();
        li.pop_front();
        v.push_back(t);
        if(li.size() > 0){
            t = li.front();
            li.pop_front();
            li.push_back(t);
        }
    }
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}
