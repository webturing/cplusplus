#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Station
{
	double price;
	int position;
};
int main(){
	double C = read<double>(), D = read<double>(), AVG = read<double>();
	int N = read();
	vector<Station>v(N);
	for(int i = 0; i < N; i++){
		v[i].price = read<double>();
		v[i].position = read<double>();
	}
	sort(v.begin(), v.end(), [](Station a, Station b)->bool{
		return a.position < b.position;
	});
	if(v[0].position > 0){
		cout << "The maximum travel distance = 0.00" << endl;
		return 0;
	}
	// for(auto i: v){
	// 	cerr << "jal::" << i.position << ' ' << i.price << endl;
	// }
	double fullDis = C * AVG;
	// cout << "fullDis = " << fullDis << endl;
	int curIndex = 0;
	double curPos, curPrice, sumPrice = 0, curCap = 0;
	while(curIndex < v.size()){
		 curPos = v[curIndex].position, curPrice = v[curIndex].price;
		 // cerr << "curIndex = " << curIndex << endl << endl;
		 int hasStation = -1, cheapestPos = -1, cheapestPos2 = -1;
		for(int i = curIndex+1; i < v.size(); i++){
			if(v[i].position > curPos + fullDis)break;
			hasStation = 1;// 范围内可达
			cheapestPos2 = i;
			if(v[i].price < curPrice){
				cheapestPos = i;
				break;// 最近的更便宜的站
			}
		}
		// cerr << "cheapestPos = "<< cheapestPos << "  cheapestPos2 = " << cheapestPos2 << endl;
		if(hasStation == 1){// 1. 范围内有可达站点
			if(cheapestPos != -1){// 1.1 有最近的便宜站点
				if(curCap * AVG >= v[cheapestPos].position - curPos){// 当前的油量可以直接到达
					curCap -= (v[cheapestPos].position - curPos)/AVG;
				}else{// 需要加油才能到达
					sumPrice += ((v[cheapestPos].position - curPos) / AVG - curCap) * curPrice; 
					curCap = 0;
				}
				curIndex = cheapestPos;
			}else{ // 2. 范围内的站点都比当前点贵，先看是否可以直接到达终点，否则把油加满开到最便宜的点。
				if(curPos + fullDis >= D){// 可以直接到达终点
					if(curCap * AVG <= D - curPos){// 2.1.1 油不足够跑到终点，先加油
						sumPrice += ((D - curPos) / AVG - curCap) * curPrice;
						curCap = 0;
					}else{
						curCap -= (D - curPos) / AVG;
					}
					break;
				}
				for(int i = curIndex+1; i < v.size(); i++){
					if(v[i].position > curPos + fullDis)break;
					if(v[i].price < v[cheapestPos2].price){
						cheapestPos2 = i;
					}
				}
				sumPrice += (C - curCap) * curPrice;
				curCap = C - (v[cheapestPos2].position - curPos) / AVG;
				curIndex = cheapestPos2;
			}
		}else{// 2. 范围内无可达站点
			if(curPos + fullDis >= D){// 2.1 可以直接到目的地
				if(curCap*AVG <= D - curPos){// 2.1.1 油不足够跑到终点，先加油
					sumPrice += ((D - curPos) / AVG - curCap) * curPrice;
					curCap = 0;
				}else{
					curCap -= (D - curPos)/AVG;
				}
				break;
			}else{
				cout << "The maximum travel distance = "<<fixed << setprecision(2) << curPos + fullDis << endl;
				return 0;
			}
		}
	}
	// cout << "curCap  = " << curCap << endl;
	cout <<fixed << setprecision(2) << sumPrice << endl;
}