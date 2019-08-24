#include<bits/stdc++.h>
using namespace std;
template <typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int type;
vector<int>preOrder, postOrder;

void BST(int left, int right){
	if(left > right)return;
	int p = left;
	for(int i = left + 1; i <= right; i++){
		if(type? preOrder[i] < preOrder[left]: preOrder[i] >= preOrder[left])break;
		p = i;
	}
	// cerr << "P = " << p << endl;
	int q = p;
	for(int i = p + 1; i <= right; i++){
		// cerr << "cmp ::" << val << " " << preOrder[i] << endl;
		if(type? preOrder[i] >= preOrder[left]: preOrder[i] < preOrder[left])break;
		q = i;
	}
	// cerr << "q = " << q << endl;
	if(q != right)return;
	BST(left+1, p);
	BST(p+1, right);
	postOrder.push_back(preOrder[left]);
}
int main(){
	int n = read();
	for(int i = 0; i < n; i++){
		preOrder.push_back(read());
	}
	type = 0;
	BST(0, n-1);
	if(postOrder.size() != n){
		type = 1;
		BST(0, n-1);
	}
	if(postOrder.size() != n){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 0; i < postOrder.size(); i++){
		if(i)cout << " " << postOrder[i];
		else cout << postOrder[i];
	}
	cout << endl;
}

/*
12
8 4 2 1 3 6 5 7 12 10 9 13


7
7 9 11 7 5 4 3

7
6 5 4 3 2 1
*/