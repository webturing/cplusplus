#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1000000 + 10;
int pp[MAXN];
int pj = 0;
bool prime[MAXN];

void sieve() {
    for (int i = 1; i < MAXN; i++)prime[i] = true;//1~n都放入筛中
    prime[1] = false;//删除1
    for (int i = 2; i * i <= MAXN; i++) {
        if (prime[i]) {//保留i
            // pp[pj++]=i;
            for (int j = i * i; j < MAXN; j += i) { //i|j
                prime[j] = false;
            }

        }
    }

}

int main() {
    sieve();
    int n = 100;
    //cin>>n;
    for (int i = 1; i <= n; i++)
        if (prime[i])cout << i << " ";
    cout << endl;
    return 0;
}