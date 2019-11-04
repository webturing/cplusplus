#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>v1(n), v2(n), v3;
	for(size_t i = 0; i < n; i++){
		cin >> v1[i];
	}
	v3 = v1;
	for(size_t i = 0; i < n; i++){
		cin >> v2[i];
	}
	int f = 0;
	for(size_t i = 1; i < n; i++){
		sort(v3.begin(), v3.begin() + i+1);
		if(f){
			cout << "Insertion Sort" << endl;
			for(size_t j = 0; j < n; j++){
				if(j){
					cout << " " << v3[j];
				}else{
					cout << v3[j];
				}
			}
			return 0;
		}
		if(v3 == v2){
			f = 1;
		}
	}
	v3 = v2;
	size_t p = n-1;
	while(v3[p] >= v3[0])p--;
	swap(v3[p], v3[0]);
	p--;
	int root = 0;
	while(root <= (p-1)/2){
		size_t q = 2*root+1;
		if(q+1 <= p and v3[q+1] > v3[q])q++;
		if(v3[q] <= v3[root])break;
		swap(v3[q], v3[root]);
		root = q;
	}
	cout << "Heap Sort" << endl;
	for(size_t j = 0; j < n; j++){
		if(j){
			cout << " " << v3[j];
		}else{
			cout << v3[j];
		}
	}
}