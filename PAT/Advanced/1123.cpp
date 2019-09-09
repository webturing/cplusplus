#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val, height, id;
	Node * left;
	Node * right;
	Node(int val):val(val), height(0){
		left = NULL;
		right = NULL;
	}
	Node(){}
};
Node* root;
int getHeight(Node* root){
	if(root == NULL)return -1;
	return root->height;
}
Node* singleRotateWithLeft(Node* root){
	Node* p = root->left;
	root->left = p->right;
	p->right = root;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	p->height = max(getHeight(p->left), getHeight(p->right))+1;
	return p;
}
Node* singleRotateWithRight(Node* root){
	Node* p = root->right;
	root->right = p->left;
	p->left = root;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	p->height = max(getHeight(p->left), getHeight(p->right))+1;
	return p;
}
Node* doubleRotateWithLeft(Node* root){
	root->left = singleRotateWithRight(root->left);
	return singleRotateWithLeft(root);
}
Node* doubleRotateWithRight(Node* root){
	root->right = singleRotateWithLeft(root->right);
	return singleRotateWithRight(root);
}
Node* insert(Node* root, int val){
	if(root == NULL){
		return new Node(val);
	}
	if(val < root->val){
		root->left = insert(root->left, val);
		if(getHeight(root->left) - getHeight(root->right) == 2){
			if(val < root->left->val){// 左子树单旋转
				root = singleRotateWithLeft(root);
			}else{// 双旋转
				root = doubleRotateWithLeft(root);
			}
		}
	}else{
		root->right = insert(root->right, val);
		if(getHeight(root->right) - getHeight(root->left) == 2){
			if(val >= root->right->val){// 右子树单旋转
				root = singleRotateWithRight(root);
			}else{
				root = doubleRotateWithRight(root);
			}
		}
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	return root;
}
int main(){
	int n;
	cin >> n;
	int x;
	cin >> x;
	Node * root = new Node(x);
	for(int i = 1; i < n; i++){
		cin >> x;
		root = insert(root, x);
	}
	queue<Node*>Q;
	Q.push(root);
	int k = 1;
	root->id = 1;
	bool f = true, first = false;
	while(Q.size()){
		Node* head = Q.front();
		if(!first){
			first = true;
			cout << head->val;
		}
		else{
			cout << " " << head->val;
		}
		Q.pop();
		if(k != head->id){
			f = false;
		}
		k++;
		if(head->left != NULL)head->left->id = 2 * head->id, Q.push(head->left);
		if(head->right != NULL)head->right->id = 2 * head->id + 1, Q.push(head->right);
	}
	cout << endl;
	if(f){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}