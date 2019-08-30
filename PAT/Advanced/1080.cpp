#include<bits/stdc++.h>
using namespace std;
struct Person
{
	int id, Ge, Gi, sum, rank;
	vector<int>school;
	bool operator<(const Person& that)const{
		if(sum != that.sum)return sum > that.sum;
		return Ge > that.Ge;
	}
};
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int>quota(m);
	for(int i = 0; i < m; i++){
		scanf("%d", &quota[i]);
	}
	vector<Person>persons(n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &persons[i].Ge, &persons[i].Gi);
		persons[i].sum = (persons[i].Ge + persons[i].Gi)/2;
		persons[i].id = i;
		for(int j = 0; j < k; j++){
			int x;
			scanf("%d", &x);
			persons[i].school.push_back(x);
		}
	}
	map<int, Person>R;
	sort(persons.begin(), persons.end());
	persons[0].rank = 1;
	R[persons[0].id] = persons[0];
	for(int i = 1; i < n; i++){
		if(persons[i-1] < persons[i]){
			persons[i].rank = i+1;
		}else{
			persons[i].rank = persons[i-1].rank;
		}
		R[persons[i].id] = persons[i];
	}
	vector<int>admission[m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < persons[i].school.size(); j++){
			int school_id = persons[i].school[j];
			if(admission[school_id].size() < quota[school_id] || R[admission[school_id].back()].rank == persons[i].rank){
				admission[school_id].push_back(persons[i].id);
				break;
			}
		}
	}
	for(int i = 0; i < m; i++){
		sort(admission[i].begin(), admission[i].end());
		for(int j = 0; j < admission[i].size(); j++){
			if(j){
				printf(" %d", admission[i][j]);
			}else{
				printf("%d", admission[i][j]);
			}
		}
		cout << endl;
	}
}