# 第二讲：字符串及其相关算法

## 一、字符串的基本应用

## 二、C++中的string类型的使用

## 三、字符串高效匹配算法：KMP算法
```
KMP算法中最难理解的就是如何求next[]数组
推荐大家去https://www.cnblogs.com/yjiyjige/p/3263858.html当中查看
下面是求next[]数组的代码
void get_next(String T, int *next) {
   int j=0;
    next[0] = -1;
    int k=-1;
    while (j < T.length-1) {
        if (k = -1 || T[j] == T[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else
            k = next[k];
    }
}


求出next[]数组过后KMP代码就很好实现了
下面是KMP的完整代码

#include<bits/stdc++.h>

using namespace std;
#define T 10000
#define P 100
int Next[T] = {0};
void get_next(char p[], int Next[]) {
    int j = 0, k = -1;
    Next[0] = -1;
    while (j < strlen(p) - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            if (p[j] != p[k])
                Next[j] = k;
            else
                Next[j] = Next[k];
        } else
            k = Next[k];
    }
}
int kmp(char t[], char p[]) {
    int i = 0, j = 0, a = strlen(t), b = strlen(p);
    while (i < a && j < b) {
        if (j == -1 || t[i] == p[j]) {
            ++i;
            ++j;
        } else
            j = Next[j];
    }
    if (j == b)
        return i - j;
    else
        return 0;
}

int main() {
    char t[T], p[P];
    scanf("%s %s", t, p);
    get_next(p, Next);
    printf("%d\n", kmp(t, p));
    return 0;
}
建议大家去OJ上面刷2069,2070
```
## 四、字符串高效查找算法：字典树Trie