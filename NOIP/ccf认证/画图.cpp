#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            arr[i][j] = 0;
    int op[4];
    for (int r = 0; r < n; r++) {
        cin >> op[0] >> op[1] >> op[2] >> op[3];
        for (int i = op[0]; i < op[2]; i++) {
            for (int j = op[1]; j < op[3]; j++) {
                arr[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            if (arr[i][j])
                cnt++;
        }
    cout << cnt << endl;
    return 0;
}
