#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  map<string, string> mp;
  mp["A"] = "I";
  mp["CMSD"] = "Love";
  mp["LMX"] = "You";
  mp["BLX"] = "eYu";
  for (string s; getline(cin, s);) {
    if (s == "END") break;
    cout << mp[s] << endl;
  }

  return 0;
}