#include<bits/stdc++.h>
using namespace std;
struct Node
{
	char name[50];
	char ID[50];
	int grade;
};
int main(){
	int n;
	scanf("%d", &n);
	vector<Node>v(n);
	for(int i = 0; i < n; i++){
		scanf("%s %s %d", v[i].name, v[i].ID, &v[i].grade);
	}
	int grade1, grade2;
	scanf("%d %d", &grade1, &grade2);
	vector<Node>v2;
	for(auto i: v){
		if(i.grade >= grade1 and i.grade <= grade2){
			v2.push_back(i);
		}
	}
	if(v2.size()==0){
		cout << "NONE" << endl;
		return 0;
	}
	sort(v2.begin(), v2.end(), [](Node a, Node b)->bool{
		return a.grade > b.grade;
	});
	for(auto i: v2){
		cout << i.name << " " << i.ID << endl;
	}
}