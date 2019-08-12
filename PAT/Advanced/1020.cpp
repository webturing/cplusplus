#include<bits/stdc++.h>
using namespace std;
template<typename T=int>
T read(){
	T x;
	cin >> x;
	return x;
}

int n = read();
vector<int>postorder(n), inorder(n);
map<int,int>traversal;
void dfs( int pb, int pe, int ib, int ie, int root){
	if(pb > pe){
		return;
	}
	traversal[root] = postorder[pe];
	int p = find(inorder.begin() + ib, inorder.begin() + ie + 1, postorder[pe]) - inorder.begin();
	int len = p - ib;
	dfs(pb, pb + len - 1, ib, p-1, 2*root);
	dfs(pb + len, pe -1, p + 1, ie, 2*root+1);
}
int main(){
	for(auto &i: postorder){
		i = read();
	}
	for(auto &i: inorder){
		i = read();
	}
	dfs(0, n-1, 0, n-1, 1);
	cout << traversal[1];
	for(auto i: traversal){
		if(i.first == 1)continue;
		cout << ' ' << i.second;
	}
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

4 1 6 3 5 7 2

     4
  1    6
   3  5 7
  2

4 1 6 3 5 7 2
*/