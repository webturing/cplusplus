#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int addr, val, next;
	bool operator==(const Node& that)const{
		return abs(val) == abs(that.val);
	}
};
int main(){
	ios::sync_with_stdio(false);
	int startAddr, n;
	cin >> startAddr >> n;
	map<int, Node>M;
	for(int i = 0; i < n; i++){
		int addr, val, next;
		cin >> addr >> val >> next;
		M[addr] = {addr, val, next};
	}
	vector<Node>v1, v2;
	map<int, int>book;
	while(startAddr != -1){
		if(book[abs(M[startAddr].val)]){
			v2.push_back(M[startAddr]);
		}else{
			v1.push_back(M[startAddr]);
			book[abs(M[startAddr].val)] = 1;
		}
		startAddr = M[startAddr].next;
	}
	for(int i = 0; i +1 < v1.size(); i++){
		cout << setw(5) << setfill('0') << v1[i].addr << " " << v1[i].val << " " << setw(5) << setfill('0')<< v1[i+1].addr << endl;
	}
	if(v1.size())
	cout << setw(5) << setfill('0') << v1.back().addr << " " << v1.back().val << " -1" << endl;
	
	for(int i = 0; i + 1< v2.size(); i++){
		cout << setw(5) << setfill('0') << v2[i].addr << " " << v2[i].val << " " << setw(5) << setfill('0')<< v2[i+1].addr << endl;
	}
	if(v2.size())
	cout << setw(5) << setfill('0') << v2.back().addr << " " << v2.back().val << " -1" << endl;

}