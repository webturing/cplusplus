#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int add, next;
	char c;
	bool f;
};
int main(){
	int head1, head2, n;
	scanf("%d %d %d", &head1, &head2, &n);
	vector<Node>v(n);
	map<int, Node>M;
	for(int i = 0; i < n; i++){
		scanf("%d %c %d", &v[i].add, &v[i].c, &v[i].next);
		M[v[i].add] = v[i];
	}
	int p = head1;
	while(~p){
		M[p].f = true;
		p = M[p].next;
	}
	p = head2;
	while(~p){
		if(M[p].f){
			cout <<setw(5) << setfill('0') << M[p].add << endl;
			return 0;
		}
		M[p].f = true;
		p = M[p].next;
	}
	cout << -1 << endl;
}