#include<stdio.h>
#include<string.h>

// 检查s是否是一个对称的字符串 s[0,n-1]
bool sysmetric(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i])return false;
    }
    return true;
}

int main() {
    char s[1000];
    scanf("%s", s);
    int n = strlen(s);//O(n)
    printf("%d\n", sysmetric(s));
    if (n % 2 == 0 and n > 0 and sysmetric(s)) {//1.长度为偶数 2非空 3对称
        s[n >> 1] = 0;//'\0'=0
        printf("%s\n", s);//还原了一次魔镜操作
    }

    return 0;
}

