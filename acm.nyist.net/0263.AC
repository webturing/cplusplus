#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct A {
    int length, diameter, number;
};

int operator<(const A &a, const A &b) {
    if (a.length != b.length)
        return a.length > b.length;
    if (a.diameter != b.diameter)
        return a.diameter < b.diameter;
    return a.number > b.number;
}

int main() {

    int cas, n;
    for (cin >> cas; cas-- && cin >> n;) {
        vector<A> pipes(n);
        for (int i = 0; i < n; i++)
            cin >> pipes[i].length >> pipes[i].diameter >> pipes[i].number;
        sort(pipes.begin(), pipes.end());
        cout << pipes[0].number << endl;
    }

    return 0;
}