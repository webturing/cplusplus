using namespace std;

int main() {
  for (float x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;)
    cout << setiosflags(ios::fixed) << setprecision(3)
         << hypot(x1 - x2, y1 - y2) << endl;
  return 0;
}