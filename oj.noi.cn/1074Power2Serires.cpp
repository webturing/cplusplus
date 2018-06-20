#include<bits/stdc++.h>

using namespace std;

string bin(int n) {
    if (n == 0)
        return "0";
    if (n == 1)
        return "2(0)";
    if (n == 2)
        return "2";
    bitset<32> b(n);
    string ans = "";
    for (int i = 0; i < b.size(); i++)
        if (b[i]) {
            if (i == 0)
                ans = "2(0)+" + ans;
            else if (i == 1)
                ans = "2+" + ans;
            else
                ans = "2(" + bin(i) + ")+" + ans;
        }
    if (ans[ans.length() - 1] == '+') ans.erase(ans.length() - 1);
    return ans;
}


int main(void) {
    int n = 137;
    cin >> n;
    cout << bin(n) << endl;
    return 0;
}