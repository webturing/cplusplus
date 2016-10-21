using namespace std;

int main() {
    for (int n; cin >> n;) {
        int a = n / 100, b = (n % 100) / 10, c = n % 10;
        cout << c * 100 + b * 10 + a << endl;
    }
    return 0;
}