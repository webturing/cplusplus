#include<iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[1005];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 0;
    int sum = 0;
    /*
    6 9
    2 6 5 6 3 5
    */
    for (int i = 0; i < n; i++) {
        //cout<<"sum="<<sum<<endl;
        if (sum < k) {
            sum += a[i];
        } else {
            sum = a[i];
            cnt++;
        }
    }
    if (sum) cnt++;

    cout << cnt << endl;
    return 0;
}
