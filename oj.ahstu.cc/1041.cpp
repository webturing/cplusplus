using namespace std;

int main() {
    for (int n; cin >> n;) {
        double s = 0;
        for (int i = 1; i <= n; i++)s += 1.0 / i;
        cout << setiosflags(ios::fixed) << setprecision(6) << s << endl;
    }
    return 0;
}