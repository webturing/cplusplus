#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &that) const {
        return this->score > that.score;
    }
};


int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    priority_queue<Student> q;
    while (n--) {
        Student t;
        cin >> t.name >> t.score;
        q.push(t);
    }
    while (--k) { q.pop(); }
    cout << q.top().name << endl;
    return 0;
}