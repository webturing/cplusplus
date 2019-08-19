#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Person
{
	string name, gender, ID;
	int grade;
};
int main(){
	int n = read();
	int min_m = INT_MAX, max_f = INT_MIN;
	Person male, female;
	for(int i = 0; i < n; i++){
		Person p;
		p.name = read<string>(), p.gender = read<string>(), p.ID = read<string>(), p.grade = read();
		if(p.gender == "M"){
			if(p.grade < min_m){
				min_m = p.grade;
				male = p;
			}
		}else{
			if(p.grade > max_f){
				max_f = p.grade;
				female = p;
			}
		}
	}
	if(max_f != INT_MIN){
		cout << female.name << " " << female.ID << endl;
	}else{
		cout << "Absent" << endl;
	}
	if(min_m != INT_MAX){
		cout << male.name << " " << male.ID << endl;
	}else{
		cout << "Absent" << endl;
	}
	if(min_m != INT_MAX and max_f != INT_MIN){
		cout << female.grade - male.grade << endl;
	}else{
		cout << "NA" << endl;
	}

}