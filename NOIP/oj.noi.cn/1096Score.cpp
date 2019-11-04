#include <bits/stdc++.h>

using namespace std;

struct Student {
    int scores[5];

    int total(vector<int> k) const {
        copy(scores, scores + 5, ostream_iterator<int>(cout, ","));
        cout << endl;
        copy(k.begin(), k.end(), ostream_iterator<int>(cout, ","));
        cout << endl;
        double s = 0;
        for (int i = 0; i < 5; i++)
            s += k[i] * scores[i];
        return s;
    }
};


int main(int argc, char const *argv[]) {
    //ifstream cin("input.txt");
    int t, q;
    cin >> t >> q;
    vector<Student> S(t);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 5; j++)
            cin >> S[i].scores[j];
    }
    while (q--) {
        vector<int> k(5);
        for (auto &i:k)cin >> i;

        int index;
        cin >> index;
        cout << S[--index].total(k) << " ";
    }
    return 0;
}