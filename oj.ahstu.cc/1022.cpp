#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> fib(2, 1);
  for (int i = 2; i <= 40; i++) fib.push_back(fib[i - 2] + fib[i - 1]);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cout << fib[i] << " ";
  cout << endl;
  return 0;
}