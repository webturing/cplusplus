#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Person
{
	int start, playing, vip;
	bool operator<(const Person& that)const{
		return start > that.start;
	}
};
struct Table
{
	int id, end, vip;
	bool operator<(const Table& that)const{
		if(end != that.end)
			return end > that.end;
		if(vip != that.vip)
			return vip < that.vip;
		return id > that.id;
	}
	bool operator==(const Table& that)const{
		return id == that.id;
	}	
};
int parseInt(string s){
	transform(s.begin(), s.end(), s.begin(), [](char c)->char{
		return c == ':'? ' ': c;
	});
	istringstream iss(s);
	int hh, mm, ss;
	iss >> hh >> mm >> ss;
	return hh * 3600 + mm * 60 + ss;
}
string toString(int n){
	ostringstream oss;
	oss << setfill('0') << setw(2) << n / 3600 << ":" << setfill('0') << setw(2) << n%3600/60 << ":" << setfill('0') << setw(2) << n%60;
	return oss.str();
}
int main(){
	const int Eight = 8 * 3600, TwentyOne = 21 * 3600;
	int n = read();
	priority_queue<Person>notVip, Vip;
	for(int i = 0; i < n; i++){
		int start = parseInt(read<string>());
		int playing = min(read(), 2 * 60);
		int vip = read();
		if(vip){
			Vip.push({start, playing, vip});
		}else{
			notVip.push({start, playing, vip});
		}
	}
	int k = read(), m = read();
	vector<Table>Tables(k+1);
	for(int i = 1; i <= k; i++){
		Tables[i] = {i, Eight, 0};
	}
	for(int i = 0; i < m; i++){
		Tables[read()].vip = 1;
	}
	map<int,int>server;
	priority_queue<Table>Q(Tables.begin()+1, Tables.end());
	while(notVip.size() or Vip.size()){
		Table head = Q.top();
		Q.pop();
		Person next;
		if(head.vip){// table is vip
			if(!Vip.size()){
				next = notVip.top();
				notVip.pop();
			}else if(!notVip.size()){
				next = Vip.top();
				Vip.pop();
			}else{
				if(notVip.top().start > Vip.top().start){
					next = Vip.top();
					Vip.pop();
				}else{
					if(head.end >= Vip.top().start){
						next = Vip.top();
						Vip.pop();
					}else{
						next = notVip.top();
						notVip.pop();
					}
				}
			}
		}else{// table is not vip
			if(!Vip.size()){
				next = notVip.top();
				notVip.pop();
			}else if(!notVip.size()){
				next = Vip.top();
				Vip.pop();
			}else{
				if(notVip.top().start < Vip.top().start){
					next = notVip.top();
					notVip.pop();
				}else{
					next = Vip.top();
					Vip.pop();
				}
			}
		}
		// cerr <<"jal:: head::" << head.id << " " << head.end << " " << head.vip << endl;
		// cerr << "jal:: next::" << next.start << endl;
		if(max(next.start, head.end) >= TwentyOne)continue;
		server[head.id]++;
		cout << toString(next.start) << ' ' << toString(max(next.start, head.end)) << ' ' << (max(next.start, head.end) - next.start) / 60 + (max(next.start, head.end) - next.start)%60/30 << endl;
		Q.push({head.id, max(next.start, head.end) + next.playing*60, head.vip});
	} 
	cout << server[1];
	for(int i = 2; i <= k; i++){
		cout << ' ' << server[i];
	}
}