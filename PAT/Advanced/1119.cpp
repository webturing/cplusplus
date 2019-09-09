#include<bits/stdc++.h>
using namespace std;
int n, f = 1;
vector<int>preorder, inorder, postorder;
void dfs(int preleft, int preright, int postleft, int postright){
	if(preleft > preright)return;//不合法
	if(preright - preleft == 1)f = 0;// 多种可能
	int p = postright-1;// 后序中右子树的根的下标
	int q = preright; // 先序中右子树的根的下标
	while(preorder[q] != postorder[p] and q >= preleft)q--;
	int leftlen = q - preleft-1;
	if(leftlen)
	dfs(preleft+1, q-1, postleft, postleft+leftlen-1);
	inorder.push_back(preorder[preleft]);
	if(preleft == preright)return;// 没有子树
	dfs(q, preright, postleft+leftlen, p);
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		preorder.push_back(x);
	}
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		postorder.push_back(x);
	}
	dfs(0, n-1, 0, n-1);
	if(f)cout << "Yes" << endl;
	else cout << "No" << endl;
	for(int i = 0; i < n; i++){
		if(i)cout << " " << inorder[i];
		else cout << inorder[i];
	}
	cout << endl;
	return 0;
}