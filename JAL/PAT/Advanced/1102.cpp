#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>Root;
struct Node
{
	int left, right;
};
map<int, Node>nodes;
vector<int>inorder, levelorder;
int root;
void dfs(int root){
	if(root == -1)return;
	dfs(nodes[root].left);
	inorder.push_back(root);
	dfs(nodes[root].right);
}
int main(){
	cin >> n;
	Root.resize(n);
	for(int i = 0; i < n; i++){
		string x, y;
		cin >> x >> y;
		if(x != "-"){
			nodes[i].left = stoi(x);
		}else{
			nodes[i].left = -1;
		}
		if(y != "-"){
			nodes[i].right = stoi(y);
		}else{
			nodes[i].right = -1;
		}
		if(nodes[i].left != -1)Root[nodes[i].left] = 1;
		if(nodes[i].right != -1)Root[nodes[i].right] = 1;
	}
	for(int i = 0; i < n; i++){
		if(!Root[i])root = i;
	}
	dfs(root);
	reverse(inorder.begin(), inorder.end());
	assert(n == inorder.size());
	queue<int>Q;
	Q.push(root);
	while(Q.size()){
		int head = Q.front();
		Q.pop();
		levelorder.push_back(head);
		if(nodes[head].right!=-1)
		Q.push(nodes[head].right);
		if(nodes[head].left!=-1)
		Q.push(nodes[head].left);
	}
	for(int i = 0; i < levelorder.size(); i++){
		if(i)cout << " " << levelorder[i];
		else cout << levelorder[i];
	}
	cout << endl;
	for(int i = 0; i < inorder.size(); i++){
		if(i)cout << " " << inorder[i];
		else cout << inorder[i];
	}
	cout << endl;
}