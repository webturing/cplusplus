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
	int score;
	string  id,name;
};
int main(){
	int n = read(), c = read();
	vector<Node>v(n);
	for(auto &i: v){
		i.id = read<string>();
		i.name = read<string>();
		i.score = read();
	}
	if(c == 1){
		sort(v.begin(), v.end(), [](Node a, Node b)->bool{
			return a.id < b.id;
		});
	}else if(c == 2){
		sort(v.begin(), v.end(), [](Node a, Node b)->bool{
			if(a.name != b.name)
				return a.name < b.name;
			return a.id < b.id;
		});
	}else{
		sort(v.begin(), v.end(), [](Node a, Node b)->bool{
			if(a.score != b.score)
				return a.score < b.score;
			return a.id < b.id;
		});
	}
	for(auto i: v){
		cout << i.id << ' ' << i.name << ' ' << i.score << endl;
	}
}