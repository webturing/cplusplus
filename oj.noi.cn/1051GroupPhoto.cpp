#include <bits/stdc++.h>

using namespace std;

struct Student {
    string gender;
    double height;

    bool operator<(const Student &that) const {
        if (gender == that.gender) {
            if (gender == "male")
                return height < that.height;
            else
                return that.height < height;
        }
        return gender == "male";
    }
};

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; i++)
        cin >> students[i].gender >> students[i].height;
    sort(students.begin(), students.end());
    bool first = true;
    for (auto s:students) {
        if (first) { first = false; }
        else { cout << " "; }
        cout << setiosflags(ios::fixed) << setprecision(2) << s.height;
    }
    cout << endl;
    return 0;
}