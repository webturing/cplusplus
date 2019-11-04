#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v(10);
    iota(v.begin(), v.end(), 2);//??a[0]=1 a[i]=a[i-1]+1????

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    array<int, 10> a;
    iota(a.begin(), a.end(), 3);

    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}