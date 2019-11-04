#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id, leaf, tot;
	double p;
	bool operator<(const Node & that)const{
		if(p != that.p)
		return p < that.p;
		return id < that.id;
	}
};
int main(){
	int n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	vector<int>M[n];
	vector<Node>nodes(n);
	for(int i = 0; i < n; i++){
		int t;
		scanf("%d", &t);
		Node node;
		node.id = i;
		if(t){
			while(t--){
				int x;
				scanf("%d", &x);
				M[i].push_back(x);
			}
			node.leaf = 0;
		}else{
			cin >> node.tot;
			node.leaf = 1;
		}
		nodes[i] = node;
	}
	nodes[0].p = p;
	vector<int>book(n);
	priority_queue<Node>Q;
	Q.push(nodes[0]);
	double result = 0;
	while(Q.size()){
		Node head = Q.top();
		Q.pop();
		if(book[head.id])continue;
		if(head.leaf){
			result += head.tot * head.p;
		}
		book[head.id] = 1;
		for(auto i: M[head.id]){
			Node node = nodes[i];
			node.p = head.p*(1+r/100);
			Q.push(node);
		}
	}
	printf("%.1f\n", result);
}