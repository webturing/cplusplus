#include<bits/stdc++.h>

using namespace std;

int main() {
    char s[1000] = "To know everything is to know nothing";
    char t[1000] = "to";
    char *pos = s;//匹配的开始位置
    pos = strstr(pos, t);
    if (pos != NULL) {//从s中找到了t
        cout << (pos - s) << endl;
    }
    pos += strlen(t);
    pos = strstr(pos, t);//从pos开始 找到t的新的首次匹配的位置
    if (pos != NULL) {//从s中找到了t
        cout << (pos - s) << endl;
    }
    return 0;
}

