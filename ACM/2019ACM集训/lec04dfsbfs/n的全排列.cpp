
//
// Created by jal on 18-9-2.
//
#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 10;
int book[MAXN];
int out[MAXN];
void dfs(int step){
    if(step >= n){
        copy(out, out+n, ostream_iterator<int>(cout, " "));//c++Êä³öÁ÷
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(book[i] == 0){
            book[i] = 1;
            out[step] = i;
            dfs(step+1);
            book[i] = 0;
        }
    }
}
int main() {

    cin >> n;
    dfs(0);
}
