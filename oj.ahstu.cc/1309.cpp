using namespace std;

int main() {
  float a, b, c;
  cin >> a >> b >> c;
  if (a + b <= c || a + c <= b || b + c <= a)
    cout << "Input error!" << endl;
  else {
    float s = (a + b + c) / 2;
    cout << setiosflags(ios::fixed) << setprecision(2)
         << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
  }
  return 0;
}