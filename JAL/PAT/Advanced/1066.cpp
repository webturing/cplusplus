#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val, height;
	Node *left, *right;	
	Node(){
		height = -1;
		left=NULL;
		right=NULL;
	}
	Node(int val):val(val), height(0){
		left=NULL;
		right=NULL;
	}
};
int getHeight(Node* root){
	if(root == NULL)return -1;
	return root->height;
}
Node* singleRotateWithRight(Node* root){// 右子树左旋
	Node* k = root->right;
	root->right = k->left;
	k->left = root;
	root->height = max(getHeight(root->left), getHeight(root->right))+1;
	k->height = max(getHeight(k->left), getHeight(k->right))+1;
	return k;
}
Node* singleRotateWithLeft(Node* root){// 左子树右旋
	Node* k = root->left;
	root->left = k->right;
	k->right = root;
	root->height = max(getHeight(root->left), getHeight(root->right))+1;
	k->height = max(getHeight(k->left), getHeight(k->right))+1;
	return k;
}
Node* doubleRotateWithRight(Node* root){// 右子树的左子树先右旋，然右子树左旋
	root->right = singleRotateWithLeft(root->right);
	return singleRotateWithRight(root);
}
Node* doubleRotateWithLeft(Node* root){// 左子树的右子树先左旋，然后左子树右旋
	root->left = singleRotateWithRight(root->left);
	return singleRotateWithLeft(root);
}
Node* insert(Node* root, int val){
	if(root == NULL){
		return new Node(val);
	}
	if(val < root->val){
		root->left = insert(root->left, val);
		if(getHeight(root->left) - getHeight(root->right) == 2){// 不平衡
			if(val < root->left->val){// 插入到了左子树的左子树， 单旋转
				root = singleRotateWithLeft(root);
			}else{// 插入到了左子树的右子树，双旋转
				root = doubleRotateWithLeft(root);
			}
		}
	}else{
		root->right = insert(root->right, val);
		if(getHeight(root->right) - getHeight(root->left) == 2){// 不平衡
			if(val >= root->right->val){// 插入到了右子树的右子树，单旋转
				root = singleRotateWithRight(root);
			}else{// 插入到了右子树的左子树，双旋转
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
	Node* root = new Node(x);
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		root = insert(root, x);
	}
	cout << root->val << endl;
}