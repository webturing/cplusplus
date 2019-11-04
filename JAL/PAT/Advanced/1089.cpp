#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>v1(n), v2(n);
	for(int i = 0; i < n; i++){
		cin >> v1[i];
	}
	for(int i = 0; i < n; i++){
		cin >> v2[i];
	}
	vector<int>v3 = v1;
	int isInsert = false;
	for(int i = 1; i < n; i++){
		int t = v3[i];
		int j = i-1;
		while(j >= 0 and v3[j] > t){
			v3[j+1] = v3[j];
			j--;
		}
		v3[j+1] = t;
		if(isInsert){
			for(int j = 0; j < n; j++){
				if(j)cout << " " << v3[j];
				else cout << v3[j];
			}
			cout << endl;
			return 0;
		}
		if(v3 == v2){
			isInsert = true;
			cout << "Insertion Sort" << endl;
		}
	}
	v3 = v1;
	int isMerge = false;
	int len = 1;
	while(1){
		len*=2;
		for(int i = 0; i < n; i += len){
			sort(v3.begin()+i, v3.begin()+min(i+len, n));
		}
		if(isMerge){
			for(int j = 0; j < n; j++){
				if(j)cout << " " << v3[j];
				else cout << v3[j];
			}
			cout << endl;
			return 0;
		}
		if(v3 == v2){
			isMerge = true;
			cout << "Merge Sort" << endl;
		}
	}
}