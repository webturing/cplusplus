#include<bits/stdc++.h>
using namespace std;
struct Node
{
    string op;
    int left, right;
};
map<int, Node>M;
string dfs(int root){
    if(M[root].left == -1 and M[root].right == -1){// 叶节点直接返回(a)这种形式
        return "(" + M[root].op + ")";
    }
    if(M[root].left == -1){// 没有左子树，只有右子树，则M[root].op是一个+-符号，这是一个一元运算符。返回(-a)这种形式
        return "(" + M[root].op + dfs(M[root].right) + ")";
    }
    return "(" + dfs(M[root].left) + dfs(M[root].right) + M[root].op + ")";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>book(n+1);
    for(int i = 1; i <= n; i++){
        string op;
        int left, right;
        cin >> op >> left >> right;
        M[i] = {op, left, right};
        if(left != -1)book[left] = 1;
        if(right != -1)book[right] = 1;
    }
    int root = -1;
    for(int i = 1; i <= n; i++){
        if(book[i]==0){// 题目中有说明parenless的节点为根节点
            root = i;
            break;
        }
    }
    cout << dfs(root) << endl;
}
