#include <bits/stdc++.h>

using namespace std;

struct Student {
    int chinese;
    int math;
    int english;
    int id;

    int total() const {
        return chinese + math + english;
    }

    bool operator<(const Student &other) const {
        int dTotal = other.total() - total();
        if (dTotal)
            return dTotal < 0;
        int dChinese = other.chinese - chinese;
        if (dChinese)
            return dChinese < 0;
        return id < other.id;

    }
};

int main(int argc, char const *argv[]) {
    for (int n; cin >> n;) {
        vector<Student> students(n);
        int id = 0;
        for (auto &s:students) {
            s.id = ++id;
            cin >> s.chinese >> s.math >> s.english;
        }
        sort(students.begin(), students.end());
        for (auto i = students.begin(); i < students.begin() + 5; ++i)
            cout << i->id << " " << i->total() << endl;
    }

    return 0;
}