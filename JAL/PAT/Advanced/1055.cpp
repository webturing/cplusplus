#include<bits/stdc++.h>
using namespace std;
template<typename T =int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Node
{
	int age, val;
	string name;
};
int main(){
	int n = read(), k = read();
	vector<Node>v(n);
	for(int i = 0; i < n; i++){
		v[i].name = read<string>();
		v[i].age = read();
		v[i].val = read();
	}
	sort(v.begin(), v.end(), [](Node a, Node b)->bool{
		if(a.val != b.val)return a.val > b.val;
		if(a.age != b.age)return a.age < b.age;
		return a.name < b.name;
	});
	for(int t = 1; t <= k; t++){
		int M = read(), Amin = read(), Amax = read();
		printf("Case #%d:\n", t);
		int f = false;
		for(int i = 0; i < v.size() and M; i++){
			if(v[i].age >= Amin and v[i].age <= Amax){
				M--;
				f = true;
				cout << v[i].name << " " << v[i].age << " " << v[i].val << endl;
 			}
		}
		if(!f){
			cout << "None" << endl;
		}
	}
}