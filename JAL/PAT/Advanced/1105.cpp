#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int>v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int n = sqrt(N);
	while(N % n != 0)n--;
	int m = N / n;
	vector<vector<int>>a(m);
	for(auto &i: a){
		i.resize(n);
	}
	int i = 0, j = 0, k = 0;
	int left = 0, right = n-1, up = 0, down = m-1;
	while(k < N){
		while(j >= left and j <= right and k < N){
			a[i][j++] = v[k++];
		}
		up++;
		i++;j--;
		while(i >= up and i <= down and k < N){
			a[i++][j] = v[k++];
		}
		right--;
		i--;j--;
		while(j >= left and j <= right and k < N){
			a[i][j--] = v[k++];
		}
		down--;
		i--;j++;
		while(i >= up and i <= down and k < N){
			a[i--][j] = v[k++];
		}
		left++;
		i++;j++;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(j){
				cout << " " << a[i][j];
			}else{
				cout << a[i][j];
			}
		}cout << endl;
	}
	return 0;
}