//
// Created by jal on 18-6-25.
//
//137 = 2(2(2)+2+2(0))+2(2+2(0))+2(0)
#include <bits/stdc++.h>
using namespace std;
void print(int n){
    if(n == 0){
        cout <<"0";
    }
    if (n == 2){
        cout << "2";
        return;
    }
    if(n==1){
        cout << "2(0)";
        return;
    }
    vector<int>v;
    int highmost_one = 0;
    while(n){
        v.push_back(n%2);
        n/=2;
    }
    for(int i = v.size() - 1; i  >= 0; i--){
        if(v[i]){
            highmost_one = i;
            break;
        }
    }
    //cout << "high:"<<highmost_one << endl;
    if(highmost_one == 1){
        cout << "2";
    }else if(highmost_one == 0){
        cout <<"2(0)";
    }else{
        cout <<"2(";
        print(highmost_one);
        cout <<")";
    }
    for(auto i = highmost_one - 1; i >= 0; i--){
        if(v[i]){
            if(i == 1){
                cout << "+2";
            }else if (i == 0){
                cout <<"+2(0)";
            }
            else{
                cout <<"+2(";
                print(i);
                cout <<")";
            }
        }
    }
}
int main(){
   // ifstream cin("input.txt");
    int n;
    cin >>n;
    print(n);
}