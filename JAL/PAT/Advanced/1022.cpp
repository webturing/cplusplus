#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Book
{
	string id, year, title, author, publisher, keyWords;
};
int main(){
	int n = read();
	vector<Book>v(n);
	cin.get();
	map<string, set<string>>Title, Author, Publisher, Keys, Year;
	for(int i = 0; i < n; i++){
		getline(cin, v[i].id);
		getline(cin, v[i].title);
		getline(cin, v[i].author);
		getline(cin, v[i].keyWords);
		getline(cin, v[i].publisher);
		getline(cin, v[i].year);
		Title[v[i].title].insert(v[i].id);
		Author[v[i].author].insert(v[i].id);
		Publisher[v[i].publisher].insert(v[i].id);
		Year[v[i].year].insert(v[i].id);
		istringstream iss(v[i].keyWords);
		string key;
		while(iss >> key){
			Keys[key].insert(v[i].id);
		}
	}
	int m = read();
	cin.get();
	string s;
	for(int i = 0; i < m; i++){
		getline(cin, s);
		cout << s << endl;
		if(s[0] == '1'){
			string title = s.substr(3);
			if(Title[title].size()){
				for(auto j: Title[title]){
					cout << j << endl;
				}
			}else{
				cout << "Not Found" << endl;
			}
		}else if(s[0] == '2'){
			string author = s.substr(3);
			if(Author[author].size()){
				for(auto j: Author[author]){
					cout << j << endl;
				}
			}else{
				cout << "Not Found" << endl;
			}
		}else if(s[0] == '3'){
			string key = s.substr(3);
			if(Keys[key].size()){
				for(auto j: Keys[key]){
					cout << j << endl;
				}
			}else{
				cout << "Not Found" << endl;
			}
		}else if(s[0] == '4'){
			string publisher = s.substr(3);
			if(Publisher[publisher].size()){
				for(auto j: Publisher[publisher]){
					cout << j << endl;
				}
			}else{
				cout << "Not Found" << endl;
			}
		}else if(s[0] == '5'){
			string year = s.substr(3);
			if(Year[year].size()){
				for(auto j: Year[year]){
					cout << j << endl;
				}
			}else{
				cout << "Not Found" << endl;
			}
		}
	}
}