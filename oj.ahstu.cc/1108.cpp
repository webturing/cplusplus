using namespace std;

int main() {
  for (int n; cin >> n;) {
    if (n < 0 || n > 100)
      cout << "Score is error!" << endl;
    else if (n < 60)
      cout << "E" << endl;
    else if (n < 70)
      cout << "D" << endl;
    else if (n < 80)
      cout << "C" << endl;
    else if (n < 90)
      cout << "B" << endl;
    else
      cout << "A" << endl;
  }
  return 0;
}