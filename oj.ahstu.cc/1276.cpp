using namespace std;

int main() {
    for (float f; cin >> f;)
        cout << setiosflags(ios::fixed) << setprecision(3) << 5 * (f - 32) / 9 << endl;
    return 0;
}