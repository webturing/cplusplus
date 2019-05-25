/*
160
50+50+50+10-->7+7+7+1=22
160
50+50+30+30-->7+7+4+4=15
*/
#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n) {
        while (n >= 50) {
            cnt += 7;
            n -= 50;
        }
        while (n >= 30) {
            cnt += 4;
            n -= 30;
        }
        if (n < 30) {
            cnt += (n / 10);
            n = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
