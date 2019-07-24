
#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int in[N];
  int result[N];
  int dp[N];
  for (int i = 0; i < N; ++i) cin >> in[i];
  dp[0] = max(in[0], 0);  //动态规划，初始状态定义
  for (int i = 1; i < N; ++i) {
    if (dp[i - 1] + in[i] < 0)
      dp[i] = max(in[i], 0);
    else
      dp[i] = dp[i - 1] + in[i];
  }
  //至此，dp（dynamic programming）数组结束

  int maxid = 0;
  for (int i = 0; i < N; ++i)  //这个循环：找最大的序列和
  {
    if (dp[i] > dp[maxid]) maxid = i;
  }
  if (dp[maxid] > 0) {
    int temp = maxid;
    int i = 0;
    while (dp[temp] > 0) {
      result[i] = in[temp];
      --temp;
      ++i;
    }
    cout << dp[maxid] << " " << result[i - 1] << " " << result[0] << endl;
  } else {
    int j;
    for (j = 0; j < N; ++j) {
      if (in[j] == 0) break;
    }
    if (j < N - 1 || in[N - 1] == 0)
      cout << "0 0 0" << endl;
    else
      cout << "0 " << in[0] << " " << in[N - 1] << endl;
  }
  return 0;
}
