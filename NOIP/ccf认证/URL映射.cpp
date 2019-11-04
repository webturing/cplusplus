#include<iostream>

using namespace std;

bool match(string test, string url[], string example[]) {
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    string url[n];
    string example[n];
    string test[m];

    for (int i = 0; i < n; i++) {
        cin >> url[i];
        cin >> example[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> test[i];
        if (match(test[i], url, example)) {

        } else cout << "404" << endl;
    }
    return 0;
}
