#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string>v(4);
	for(int i = 0; i < v.size(); i++){
		cin >> v[i];
	}
	int i = 0;
	int w, h, m;
	vector<string>week{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	for(; i < min(v[0].size(), v[1].size()); i++){
		if(v[0][i] == v[1][i] and v[0][i] <= 'G' and v[0][i] >= 'A'){
			w = v[0][i] - 'A';
			break;
		}
	}
	i++;
	for(; i < min(v[0].size(), v[1].size()); i++){
		if(v[0][i] == v[1][i]){
			if(isdigit(v[0][i])){
				h = v[0][i] - '0';
				break;
			}else if(v[0][i] >='A' and v[0][i] <= 'N'){
				h = v[0][i] - 'A' + 10;
				break;
			}
		}
	}
	for(int i = 0; i < min(v[2].size(), v[3].size()); i++){
		if(isalpha(v[2][i]) and v[2][i] == v[3][i]){
			m = i;
			break;
		}
	}
	printf("%s %02d:%02d\n", week[w].c_str(), h, m);
}