#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id, weight, rank, order;
};
int main(){
	int Np, Ng;
	cin >> Np >> Ng;
	vector<Node>v(Np);
	for(int i = 0; i < Np; i++){
		v[i].id = i;
		cin >> v[i].weight;
	}
	for(int i = 0; i < Np; i++){
		int x;
		cin >> x;
		v[x].order = i;
	}
	vector<Node>v2(v);
	sort(v2.begin(), v2.end(), [](Node a, Node b)->bool{
		return a.order < b.order;
	});
	map<int, vector<Node>>M;
	do{
		M.clear();
		for(int i = 0; i < v2.size(); i++){
			M[i/Ng].push_back(v2[i]);
		}
		int rank = M.size()+1;
		vector<Node>newArr;
		for(int i = 0; i < M.size(); i++){
			sort(M[i].begin(), M[i].end(), [](Node a, Node b)->bool{
				return a.weight > b.weight;
			});
			newArr.push_back(M[i].front());
			for(int j = 1; j < M[i].size(); j++){
				v[M[i][j].id].rank = rank;
			}
		}
		for(int i = 0; i < newArr.size(); i++){
			newArr[i].order = i;
		}
		v2 = newArr;
	}while(v2.size()!=1);
	v[v2.front().id].rank = 1;
	for(int i = 0; i < v.size(); i++){
		if(i)cout << " " << v[i].rank;
		else cout << v[i].rank;
	}
	cout << endl;
}