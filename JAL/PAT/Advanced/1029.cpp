#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	scanf("%d", &x);
	return x;
}
int main(){
	int n = read();
	queue<int>QA, QB;
	for(int i = 0; i < n; i++){
		QA.push(read());
	}
	int m = read();
	int res = 0;
	for(int i = 0; i <= (m+n-1)/2; i++){
		if(i < m){
			QB.push(read());
		}
		if(QA.empty()){
			res = QB.front();
			QB.pop();
		}
		else if(QB.empty()){
			res = QA.front();
			QA.pop();
		}
		else{
		 	if(QA.front() < QB.front()){
		 		res = QA.front(), QA.pop();
		 	}else{
				res = QB.front(), QB.pop();
		 	}	
		}
	}	
	cout << res << endl;
}
