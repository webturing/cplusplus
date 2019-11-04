#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int max = 0;
    int temp = 0;
    int result = arr[0];

    for (int i = 0; i < n; i++) {
        temp = 0;
        for (int j = i; j < n; j++) {
            if (arr[i] == arr[j]) {
                temp++;
                //cout<<arr[i]<<"*** "<<j<<"***"<<i<<endl;
            } else {    //cout<<arr[i]<<" "<<temp<<endl;
                if (max < temp) {
                    max = temp;
                    result = arr[i];
                } else if (max == temp) {
                    if (result > arr[i])
                        result = arr[i];
                }
                i = j - 1;
                j = n;
            }
        }
    }
    cout << result << endl;
    return 0;
}
