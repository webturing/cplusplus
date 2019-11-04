#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Stu
{
	string id;
	int score, final_rank, location_numnber, local_rank;
};
int main(){
	int t = read();
	vector<Stu>v;
	for(int i = 1; i <= t; i++){
		int n = read();
		vector<Stu>v2;
		for(int j = 0; j < n; j++){
			string id = read<string>();
			int score = read();
			v2.push_back({id, score, 0, i, 0});
		}
		sort(v2.begin(), v2.end(), [](Stu a, Stu b)->bool{
			return a.score > b.score;
		});
		v2[0].local_rank = 1;
		for(int j = 1; j < n; j++){
			v2[j].local_rank = v2[j-1].score == v2[j].score ? v2[j-1].local_rank: j+1;
		}
		v.insert(v.begin(), v2.begin(), v2.end());
	}
	sort(v.begin(), v.end(), [](Stu a, Stu b)->bool{
		if(a.score != b.score)
			return a.score > b.score;
		return a.id < b.id;
	});
	v[0].final_rank = 1;
	for(int i = 1; i < v.size(); i++){
		v[i].final_rank = v[i-1].score == v[i].score? v[i-1].final_rank: i+1;
	}
	cout << v.size() << endl;
	for(auto i: v){
		cout << i.id << ' ' << i.final_rank << ' ' << i.location_numnber << ' ' << i.local_rank << endl;
	}
}