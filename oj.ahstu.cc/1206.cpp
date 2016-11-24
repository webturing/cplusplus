using namespace std;

int main(int argc, char const *argv[]) {
  vector<bool> prime(1001, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < prime.size(); i++)
    if (prime[i])
      for (int j = i * i; j < prime.size(); j += i) prime[j] = false;
  for (int M; cin >> M;)
    for (int N; M-- && cin >> N;) {
      int s = 0;
      for (int t; N-- && cin >> t;)
        if (prime[t]) s += t;
      cout << s << endl;
    }
  return 0;
}