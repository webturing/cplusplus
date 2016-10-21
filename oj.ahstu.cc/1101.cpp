using namespace std;

int main() {
    for (int n; cin >> n;)
        for (int a, b; n-- && cin >> a >> b; cout << (a + b) % 100 << endl);
    return 0;
}