#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Node
{
	int addr, val, next;
};
int main(){
	int n = read();
	int startAddr = read();
	map<int, Node>M;
	vector<Node>v;
	for(int i = 0; i < n; i++){
		int addr = read();
		int val = read();
		int next = read();
		M[addr] = {addr, val, next};
	}
	while(~startAddr){
		v.push_back(M[startAddr]);
		startAddr = M[startAddr].next;
	}
	n = v.size();
	if(n == 0){
		cout << "0 -1" << endl;
		return 0;
	}
	sort(v.begin(), v.end(), [](Node a, Node b)->bool{
		return a.val < b.val;
	});
	printf("%d %05d\n", n, v[0].addr);
	for(int i = 0; i < n-1; i++){
		printf("%05d %d %05d\n", v[i].addr, v[i].val, v[i+1].addr);
	}
	printf("%05d %d -1\n", v.back().addr, v.back().val);

}