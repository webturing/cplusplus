#include <bits/stdc++.h>

using namespace std;

struct Volunteer {
    int number;
    int score;

    bool operator<(const Volunteer &other) const {
        if (this->score != other.score)
            return this->score > other.score;
        return this->number < other.number;
    }
};

int main(int argc, char const *argv[]) {
    for (int n, m; cin >> n >> m;) {
        vector<Volunteer> volunteers(n);
        for (auto &v:volunteers)cin >> v.number >> v.score;
        sort(volunteers.begin(), volunteers.end());
        int select = (int) (m * 1.5);
        int minScore = volunteers[select - 1].score;
        auto right = volunteers.begin();
        while (right < volunteers.end() && right->score >= minScore)
            ++right;
        cout << minScore << " " << right - volunteers.begin() << endl;
        for (auto i = volunteers.begin(); i != right; i++)
            cout << i->number << " " << i->score << endl;

    }
    return 0;
}