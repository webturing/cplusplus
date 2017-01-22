#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  const string COMMENT = "//";
  for (string s; getline(cin, s);) {
    int pos = s.find(COMMENT);
    if (pos == 0) continue;
    if (pos != string::npos)
      cout << s.substr(0, pos) << endl;
    else
      cout << s << endl;
  }
  return 0;
}
