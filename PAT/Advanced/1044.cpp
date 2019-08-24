#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Node
{
	int left, right, sum;
	bool operator<(const Node& that)const{
		if(sum != that.sum)
			return sum < that.sum;
		return left < that.left;
	}
};
int main(){
	int n = read(), m = read();
	vector<int>v;
	for(int i = 0; i < n; i++){
		v.push_back(read());
	}
	deque<pair<int, int>>D;
	vector<Node>res;
	int sum = 0;
	for(int i = 0; i < n; i++){
		while(sum >= m){
			res.push_back({D.front().first+1, i, sum});
			sum -= D.front().second;
			D.pop_front();
		}
		D.push_back({i, v[i]});
		sum += v[i];
	}
	while(sum >= m){
		res.push_back({D.front().first+1, n, sum});
		sum -= D.front().second;
		D.pop_front();
	}
	sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); i++){
		if(res[i].sum > res[0].sum)break;
		cout << res[i].left << '-' << res[i].right  << endl;
	}
}