#include<bits/stdc++.h>
using namespace std;
struct Node
{
	string id;
	int time;
	string tag;
	bool operator<(const Node& that)const{
		if(time != that.time){
			return time < that.time;
		}
		return id < that.id;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	map<string, vector<Node>>M;
	for(int i = 0; i < n; i++){
		string id, t, tag;
		cin >> id >> t >> tag;
		int hh = stoi(t.substr(0, 2));
		int mm = stoi(t.substr(3, 2));
		int ss = stoi(t.substr(6, 2));
		int time = hh * 3600 + mm * 60 + ss;
		M[id].push_back({id, time, tag});
	}
	vector<Node>V;
	map<string, int>Sum;
	for(auto Card: M){
		sort(Card.second.begin(), Card.second.end());
		for(int i = 0; i < Card.second.size()-1; i++){
			if(Card.second[i].tag == "in" and Card.second[i+1].tag == "out"){
				V.push_back(Card.second[i]);
				V.push_back(Card.second[i+1]);
				Sum[Card.first] += Card.second[i+1].time - Card.second[i].time;
				i++;
			}
		}
	}
	sort(V.begin(), V.end());
	int p = 0, cnt = 0;
	while(k--){
		string t;
		cin >> t;
		int hh = stoi(t.substr(0, 2));
		int mm = stoi(t.substr(3, 2));
		int ss = stoi(t.substr(6, 2));
		int time = hh * 3600 + mm * 60 + ss;
		for(; p < V.size(); p++){
			if(V[p].time > time)break;
			if(V[p].tag == "out"){
				cnt--;
			}else{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	int maxn = 0;
	for(auto i: Sum){
		if(i.second > maxn)maxn = i.second;
	}
	for(auto i: Sum){
		if(i.second == maxn){
			cout << i.first << " ";
		}
	}
	cout << setw(2) << setfill('0') << maxn/3600 << ":" <<  setw(2) << setfill('0') << maxn%3600/60 << ":" <<  setw(2) << setfill('0') << maxn%60 << endl;
}