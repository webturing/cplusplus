#include<bits/stdc++.h>
using namespace std;
vector<int>preorder, inorder, postorder;
map<int, int>M;
void dfs(int preLeft, int preRight, int inLeft, int inRight){
	if(preLeft > preRight)return;
	int val = preorder[preLeft];
	int p = inLeft;
	for(int i = inLeft; i <= inRight; i++){
		if(inorder[i] == val){
			p = i;
			break;
		}
	}
	int len = p - inLeft;
	dfs(preLeft+1, preLeft+len, inLeft, p-1);
	dfs(preLeft+len+1, preRight, p+1, inRight);
	postorder.push_back(val);
}
int main(){
	int n;
	cin >> n;
	stack<int>Stk;
	for(int i = 0; i < 2*n; i++){
		string s;
		cin >> s;
		if(s == "Push"){
			int x;
			cin >> x;
			preorder.push_back(x);
			Stk.push(x);
		}else{
			inorder.push_back(Stk.top());
			Stk.pop();
		}
	}
	assert(preorder.size() == inorder.size());
	dfs(0, preorder.size()-1, 0, inorder.size()-1);
	for(int i = 0; i < postorder.size(); i++){
		if(i)cout << " " << postorder[i];
		else cout << postorder[i];
	}
	cout << endl;
}