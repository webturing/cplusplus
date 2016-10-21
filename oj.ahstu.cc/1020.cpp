using namespace std;

int main() {
    vector <int> v(10);
    for (unsigned i = 0; i < 10; i++)cin >> v[i];
    sort(v.begin(), v.end());
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)cout << *it << " ";
    cout << endl;

    return 0;
}