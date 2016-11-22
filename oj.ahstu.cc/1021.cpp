using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  int tot = 0;
  for (string::const_iterator it = s.begin(); it != s.end(); ++it)
    if (isalpha(*it)) ++tot;
  cout << tot << endl;
  return 0;
}