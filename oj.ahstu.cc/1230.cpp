using namespace std;

int main(int argc, char const *argv[]) {
  vector<bool> prime(100001, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < prime.size(); i++)
    if (prime[i])
      for (int j = i * i; j < prime.size(); j += i) prime[j] = false;

  int N, i;
  for (cin >> N, i = 1; i <= N; i++)
    if (prime[i]) cout << i << " ";
  cout << endl;
  return 0;
}