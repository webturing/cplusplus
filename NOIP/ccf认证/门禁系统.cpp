#include<iostream>
#include<map>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][2];
    map<int, int> mymap;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        if (mymap.find(arr[i][0]) == mymap.end())
            mymap[arr[i][0]] = 1;
        else mymap[arr[i][0]] += 1;
        arr[i][1] = mymap[arr[i][0]];
    }
    for (int i = 0; i < n; i++)
        cout << arr[i][1] << " ";
    return 0;
}
