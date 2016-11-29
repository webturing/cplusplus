#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  ifstream cin("d:\\data\\1186\\sample.in");
  map<char, string> mp;
  mp['0'] = "0000";
  mp['1'] = "0001";
  mp['2'] = "0010";
  mp['3'] = "0011";
  mp['4'] = "0100";
  mp['5'] = "0101";
  mp['6'] = "0110";
  mp['7'] = "0111";
  mp['8'] = "1000";
  mp['9'] = "1001";
  mp['A'] = "1010";
  mp['B'] = "1011";
  mp['C'] = "1100";
  mp['D'] = "1101";
  mp['E'] = "1110";
  mp['F'] = "1111";
  for (string s; cin >> s;) {
    for (int i = 0; i < s.length(); i++) cout << mp[s[i]];
    cout << endl;
  }
  return 0;
}