/**
Description
从前有一座庙，庙里有三个柱子，柱A柱 B柱
C。柱A有64个盘子，从上往下盘子越来越大。要求庙里的老和尚把这64个盘子全部移动到柱子C上。移动的时候始终只能小盘子压着大盘子。而且每次只能移动一个。
现在问题来了，老和尚相知道将柱A上面前n个盘子从柱A搬到柱C搬动方法。要求移动次数最少。
Input
输入有多组，每组输入一个正整数n(0<n<16)
Output
每组测试实例，输出每一步的步骤，输出“number..a..form..b..to..c”。表示将第a个盘子从柱b搬到柱c.
Sample Input
2
Sample Output
number..1..form..A..to..B
number..2..form..A..to..C
number..1..form..B..to..C

http://acm.nefu.edu.cn/JudgeOnline/problemShow.php?problem_id=564
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
void move(int n,char a,char b,char c){
	printf("number..%d..from..%c..to..%c\n",n,a,b);
}
void hanoi(int n,char a,char b,char c){
	if(n==1)move(1,a,c);
	else{
		hanoi(n-1,a,c,b);
		move(n,a,c);
		hanoi(n-1,b,a,c);
	}
}
int main(){
	int n;
	while(cin>>n)
		hanoi(n,'A','B','C');
	return 0;

}

