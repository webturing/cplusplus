#include<bits/stdc++.h>
using namespace std;
const int N = 100003;
vector<int>c(N);
stack<int>S;
int lowbit(int x){
	return x & -x;
}
void update(int index, int val){
	for(;index < N;c[index] += val, index += lowbit(index));
}
int getSum(int index){
	int ret = 0;
	for(; index > 0; ret += c[index], index -= lowbit(index));
	return ret;
}
int getMedian(){
	int n = S.size();
	int k = (n+1)/2;
	int left = 1, right = N;
	while(left < right){
		int mid = (left + right) >> 1;
		int sum = getSum(mid);
		if(sum < k){
			left = mid+1;
		}else{
			right = mid;
		}
	}
	return left;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		if(s == "Pop"){
			if(S.empty()){
				cout << "Invalid" << endl;
			}else{
				update(S.top(), -1);
				cout << S.top() << endl;
				S.pop();
			}
		}else if(s == "PeekMedian"){
			if(S.empty()){
				cout << "Invalid" << endl;
			}else{
				cout << getMedian() << endl;
			}
		}else{
			int key;
			cin >> key;
			S.push(key);
			update(key, 1);
		}
	}
}