//
// Created by jal on 18-6-25.
//

#include <bits/stdc++.h>
using namespace std;
int step = 0;
char name[4] = {' ','a','b','c'};
void move(int x, int from, int to){
    cout << ++step << ".Move " << x << " from " << name[from] << " to " << name[to] << endl;
}
void dfs(int n, int from, int to, int help){
    if(n == 1){
        move(n, from, to);
        return;
    }
    dfs(n-1, from, help, to);
    move(n, from, to);
    dfs(n-1, help, to, from);
}
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    dfs(n,1,3,2);
}