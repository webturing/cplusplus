#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
map<pair<string, string>, bool>bookEdge;
map<string, int>book;
map<string, list<pair<string,int>>>M;
map<string, int>result, Count;
string key;
int value;
int sum = 0, total = 0;
void dfs(string x){
	if(!book[x]){
		total++;
		book[x] = true;
		if(value < Count[x]){
			value = Count[x];
			key = x;
		}
	}
	for(auto i: M[x]){
		if(bookEdge[{x, i.first}])continue;
		// cerr << " jal::dfs::" << i.first << " " << i.second<< endl;
		sum += i.second;
		bookEdge[{x, i.first}] = true;
		dfs(i.first);
	}
}
int main(){
	int m = read(), k = read();
	for(int i = 0; i < m; i++){
		string name1 = read<string>(), name2 = read<string>();
		int time = read();
		M[name1].push_back({name2, time});
		Count[name1]+=time;
		Count[name2]+=time;
	}
	for(auto i: M){
		// cerr << "jal::" << i.first << ' ' << i.second.size() << endl;
		if(!book[i.first]){
			sum = 0; 
			total = 0;
			value = 0;
			dfs(i.first);
			// cerr << "jal:: sum = " << sum << " total = " << total << " value = " << value << endl;
			if(sum > k and total > 2){
				result[key] = total;
			}
		}
	}
	cout << result.size() << endl;
	for(auto i: result){
		cout << i.first << ' ' << i.second << endl;
	}
}