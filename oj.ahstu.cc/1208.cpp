using namespace std;

int main() {
    int a, n, m;
    for (cin >> a; a-- && cin >> n >> m;) {
        if (n >= 0 && m >= 0 && m % 2 == 0 && m >= 2 * n && m <= 4 * n) {
            cout << (4 * n - m) / 2 << " " << (m - 2 * n) / 2 << endl;
        } else
            cout << "No answer\n";
    }
    return 0;
}