#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int user;
	vector<int>problems;
	int sum;
	int total;
	int rank;
};
int main(){
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	vector<int>full(k+1);
	for(int i = 1; i <= k; i++){
		scanf("%d", &full[i]);
	}
	map<int, bool>book;
	vector<Node>v;
	map<int, vector<int>>M;
	for(int i = 0; i < m; i++){
		int user_id, problem_id, score;
		scanf("%d %d %d", &user_id, &problem_id, &score);
		if(score != -1){
			book[user_id] = true;
		}
		if(!M[user_id].empty()){
			if(M[user_id][problem_id] < score)
				M[user_id][problem_id] = score;
		}else{
			M[user_id].resize(k+1);
			for(auto &j: M[user_id])j = -2;
			M[user_id][problem_id] = score;
		}
	}
	for(auto i: M){
		if(!book[i.first])continue;
		int sum = 0, total = 0;
		for(int j = 1; j <= k; j++){
			if(i.second[j]>0)sum += i.second[j];
			if(i.second[j] == full[j])total++;
		}
		v.push_back({i.first, i.second, sum, total});
	}
	sort(v.begin(), v.end(), [](Node a, Node b)->bool{
		if(a.sum != b.sum)return a.sum > b.sum;
		if(a.total != b.total)return a.total > b.total;
		return a.user < b.user;
	});
	v[0].rank = 1;
	for(int i = 1; i < v.size(); i++){
		if(v[i].sum == v[i-1].sum){
			v[i].rank = v[i-1].rank;
		}else{
			v[i].rank = i+1;
		}
	}
	for(auto i: v){
		printf("%d %05d %d", i.rank, i.user, i.sum);
		for(int j = 1; j <= k; j++){
			if(i.problems[j] == -2){
				printf(" -");
			}else if(i.problems[j] == -1){
				printf(" 0");
			}else{
				printf(" %d", i.problems[j]);
			}
		}
		printf("\n");
	}
}