#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == -arr[j]) {
                cnt++;
                //arr[j]=arr[i];
            }
        }
    }
    cout << cnt;
    return 0;
}
