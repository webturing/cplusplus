
#include <iostream>
using namespace std;
int main() {
  for (int score; cin >> score;) {
    if (score < 0 || score > 100)
      cout << "Score is error!" << endl;
    else if (score < 60)
      cout << "E" << endl;
    else if (score < 70)
      cout << "D" << endl;
    else if (score < 80)
      cout << "C" << endl;
    else if (score < 90)
      cout << "B" << endl;
    else
      cout << "A" << endl;
  }

  return 0;
}
