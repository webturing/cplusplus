#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  for (string text, keyword; cin >> text >> keyword;) {
    int tot = 0;
    while (true) {
      size_t pos = text.find(keyword);
      if (pos == string::npos) break;
      ++tot;
      text = text.substr(pos + keyword.length());
    }
    cout << tot << endl;
  }
  return 0;
}