#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id, virtue, talent, type, sum;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n, L, H;
	cin >> n >> L >> H;
	vector<Node>v;
	for(int i = 0; i < n; i++){
		int id, talent, virtue, sum;
		cin >> id >>virtue >> talent;
		if(talent < L || virtue < L)continue;
		sum = talent + virtue;
		int type;
		if(talent >= H and virtue >= H){
			type = 1;
		}else if(virtue >= H){
			type = 2;
		}else if(virtue >= talent){
			type = 3;
		}else{
			type = 4;
		}
		v.push_back({id, virtue, talent, type, sum});
	}
	sort(v.begin(), v.end(), [](Node a, Node b)->bool{
		if(a.type != b.type){
			return a.type < b.type;
		}
		if(a.sum != b.sum)
			return a.sum > b.sum;
		if(a.virtue != b.virtue)
			return a.virtue > b.virtue;
		return a.id < b.id;
	});
	cout << v.size() << endl;
	for(auto i: v){
		cout << setw(8) << setfill('0') <<i.id << " " << i.virtue << " " << i.talent << endl;
	}
}