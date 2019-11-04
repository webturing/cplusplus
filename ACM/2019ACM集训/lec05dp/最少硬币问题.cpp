/* 
Aoj 题目

1353: 算法实现题 3-2 最少硬币问题（习题 3-4）

Time Limit: 1 Sec  Memory Limit: 128 MB

Description

设有 n 种不同面值的硬币，各硬币的面值存于数组 T[1:n]中。现要用这些面值的硬币来找钱。可以使用的各种面值的硬币个数存于数组 Coins[1:n]中。对任意钱数 0≤m≤20001，设计一个用最少硬币找钱 m 的方法。
算法设计：
对于给定的 1≤n≤10，硬币面值数组 T 和可以使用的各种面值的硬币个数数组 Coins，以及钱数 m，0≤m≤20001，计算找钱 m 的最少硬币数。

Input

第一行中只有 1 个整数给出n 的值,第 2 行起每行	2 个数，分别是 T[j]和 Coins[j]。最后 1 行是要找的钱数 m。
Output

将计算出的最少硬币数输出
Sample Input

3
1 3
2 3
5 3
18
Sample Output

5

*/

/*
看似这个题目是一个贪心算法的题目，但是贪心算法并不是一定能求出最优解。
这个题目可以转化成动态规划的背包问题，就可以很好的解决这个问题
*/

#include<iostream>
#include<algorithm>
#include<cstring>
 
using namespace std;
int dp[200010];
int main()
{
    int num[11],n[11];
    int t,m;
 
    while(cin>>t)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0; i<t; i++)
            cin>>num[i]>>n[i];
        cin>>m;
        dp[0]=1;
        for(int i=0; i<t; i++)
        {
            for(int k=0; k<n[i]; k++)
            {
                for(int j=m; j>=0; j--)
                {
                    if(dp[j])
                    {
                        dp[j+num[i]]=dp[j]+1;
                    }
                }
            }
        }
        if(dp[m])
            cout<<dp[m]-1<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}