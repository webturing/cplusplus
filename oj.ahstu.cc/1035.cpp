#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

int main() {
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_insert_iterator<vector<int> >(v));
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
