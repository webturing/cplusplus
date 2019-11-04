/**
Description
有个人赶着鸭子去每个村庄卖，每经过一个村子卖去所赶鸭子的一半又2只。这样他经过了n个村子后还剩两只鸭子，问他出发时共赶多少只鸭子？
Input
输入有多组数据，每组数据占一行，包含唯一的正整数n.(0 < n <= 60).
Output
每组测试实例，输出一行，第一行输出出发时共赶了多少只鸭子。
Sample Input
1
2
Sample Output
8
20
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f(int n){
	if (n==1)
			return 2;
	return 2*f(n-1)+2;
}
int main(){
	int n;
	while(cin>>n)
		cout<<f(n)<<endl;
	return 0;

}

