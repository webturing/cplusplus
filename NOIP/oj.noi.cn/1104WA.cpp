#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string fmt(const double exp, int scale = 3) {
    ostringstream os;
    os << setiosflags(ios::fixed) << setprecision(scale) << exp;
    return os.str();
}

#define LOCAL

struct Sol {
    int mass;
    int vol;

    friend istream &operator>>(istream &is, Sol &sol) {
        is >> sol.mass >> sol.vol;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Sol &sol) {
        os << "mass:" << sol.mass << ",vol:" << sol.vol;
        return os;
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    assert(cin);
    LL start = clock();
#endif
    int n;
    cin >> n;
    vector<Sol> S(1 + n);
    for (int i = 1; i <= n; i++)cin >> S[i];
    int q;
    cin >> q;
    while (q--) {
        string op;
        cin >> op;
        if (op == "E") {
            int L, R;
            cin >> L >> R;
            double mass = 0;
            for (int i = L; i <= R; i++)mass += S[i].mass;
            double vol = 0;
            for (int i = L; i <= R; i++)vol += S[i].vol;
            cout << fmt(mass / vol) << endl;
        } else if (op == "I") {
            int x;
            cin >> x;
            Sol *sol = new Sol;
            cin >> *sol;
            S.insert(S.begin() + x, *sol);
        } else if (op == "D") {
            int x;
            cin >> x;
            S.erase(S.begin() + x);
        }

    }

#ifdef LOCAL
    LL end = clock();
    cerr << "Elapsed " << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}
