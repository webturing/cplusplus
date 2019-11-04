
#include <stdio.h>
#include <string.h>
int digit[10];  //静态初始化数组，默认值为0
int main() {
  char ch[21];  // 20个以内的数字
  scanf("%s", ch);
  int len = strlen(ch), num, i, flag = 0;
  for (i = len - 1; i >= 0; i--) {
    num = ch[i] - '0';  // char 转 int
    digit[num]++;
    num = num * 2 + flag;  // flag是进制
    flag = 0;
    if (num >= 10) {
      num -= 10;
      flag = 1;
    }
    ch[i] = (num + '0');  // int 转 char
    digit[num]--;
  }
  int flag1 = 0;  //优化输出
  for (i = 0; i < 10; i++) {
    if (digit[i] != 0) {
      flag1 = 1;
      break;
    }
  }
  printf("%s", (flag1 == 1) ? "No\n" : "Yes\n");
  if (flag == 1)
    printf("1");  // 不要忘了x2后，进制可能会加一的情况（超过了20个数）
  printf("%s", ch);
  return 0;
}