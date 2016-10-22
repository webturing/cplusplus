using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    cout << (a / 10 + b / 10) % 10 * 10 + (a % 10 + b % 10) % 10 << endl;
    return 0;
}