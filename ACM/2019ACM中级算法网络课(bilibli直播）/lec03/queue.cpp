#include<bits/stdc++.h>

using namespace std;
//int data[1000],head,tail;

int main() {
    queue<int> Q;//FIFO
    for (int i = 0; i < 10; i++)Q.push(i);//0~9依次入队
    while (not Q.empty()) {
        cout << Q.front() << endl;//队头元素
        Q.pop();//
    }
    return 0;
}