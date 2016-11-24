using namespace std;

int main() {
  for (float r, h, pi = atan(1.) * 4; cin >> r >> h;)
    cout << "Area=" << setiosflags(ios::fixed) << setprecision(3)
         << 2 * pi * r * (r + h) << endl;
  return 0;
}