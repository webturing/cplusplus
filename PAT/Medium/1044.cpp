#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> Mars = {
    {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep",
     "oct", "nov", "dec"},
    {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy",
     "lok", "mer", "jou"}};

void etom(int e) {
  if (e >= 13)
    cout << Mars[1][e / 13] << " " << Mars[0][e % 13];
  else
    cout << Mars[0][e % 13];
  cout << endl;
}
void mtoe(string m) {
  istringstream iss(m);
  string a, b;
  if (iss >> a >> b) {
    int n = find(Mars[1].begin(), Mars[1].end(), a) - Mars[1].begin();
    int m = find(Mars[0].begin(), Mars[0].end(), b) - Mars[0].begin();
    cout << n * 13 + m << endl;
  } else {
    int m = find(Mars[0].begin(), Mars[0].end(), a) - Mars[0].begin();
    cout << m << endl;
  }
}
int main() {
  ifstream cin("input.txt");
  string s;
  getline(cin, s);
  int N = stoi(s);
  while (N--) {
    getline(cin, s);
    istringstream iss(s);
    int e;
    if (iss >> e) {
      etom(e);
    } else {
      mtoe(s);
    }
  }
  return 0;
}