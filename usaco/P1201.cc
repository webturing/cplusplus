#include <bits/stdc++.h>

using namespace std;

int main() {
    int np;
    cin >> np;
    vector<string> persons(np);
    map<string, int> mp;
    for (auto &person : persons) {
        cin >> person;
        mp[person] = 0;
    }
    for (int i = 0; i < np; i++) {
        string sender;
        int amount, ng;
        cin >> sender >> amount >> ng;
        if (amount == 0 && ng == 0) continue;
        amount /= ng;
        while (ng--) {
            string reciever;
            cin >> reciever;
            mp[reciever] += amount;
            mp[sender] -= amount;
        }
    }
    for (auto person : persons) cout << person << " " << mp[person] << endl;
    return EXIT_SUCCESS;
}