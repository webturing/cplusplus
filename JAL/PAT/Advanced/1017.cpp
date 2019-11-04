#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct ZJ{
	int time;
	int len;
	int start, end;
	bool operator<(const ZJ&that)const {
		return end > that.end;
	}
};
int parseInt(string s){
	transform(s.begin(), s.end(), s.begin(), [](char c)->char{
		return c == ':' ? ' ' : c;
	});
	istringstream iss(s);
	int h, m, ss;
	iss >> h >> m >> ss;
	int ret  = h * 3600 + m * 60 + ss;
	return ret;
}
int main(){
	freopen("input.txt", "r", stdin);
	int n = read(), k = read();
	vector<ZJ>V(n);
	for(auto &i: V){
		i.time = parseInt(read<string>());
		i.len = read();
	} 
	sort(V.begin(), V.end(), [](ZJ z1, ZJ z2)->bool{
		return z1.time < z2.time; 
	});
	priority_queue<ZJ>Q;
	int t = min(n, k);
	int Eight = 8 * 3600, Fifth = 17 * 3600;
	int sum = 0, total = 0;
	for(int i = 0; i < t; i++){
		if(V[i].time > Fifth)break;
		V[i].start = max(V[i].time, Eight);
		V[i].end = V[i].start + V[i].len * 60;
		sum += V[i].start - V[i].time;
		total ++;
		Q.push(V[i]);
	}
	while(t < n){
		ZJ head = Q.top();
		Q.pop();
		if(V[t].time > Fifth)break;
		V[t].start = max(V[t].time, head.end);
		V[t].end = V[t].start + V[t].len * 60;
		sum += V[t].start - V[t].time;
		total ++;
		Q.push(V[t]);
		t++;
	}
	cout << fixed << setprecision(1) << sum / 60.0 / total <<endl;
} 
