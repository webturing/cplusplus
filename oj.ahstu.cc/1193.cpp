#include <stdio.h>
#include <string.h>
struct {
  char name[22];
  int qimo;
  int banyi;
  char bangan[10];
  char xibu[10];
  int lunwen;
  int jiangjin;
} data[110];
int main() {
  int x;
  int i, tsum, t, k;
  scanf("%d", &x);
  for (i = 0; i < x; i++) data[i].jiangjin = 0;
  for (i = 0; i < x; i++)
    scanf("%s %d %d %s %s %d", data[i].name, &data[i].qimo, &data[i].banyi,
          data[i].bangan, data[i].xibu, &data[i].lunwen);
  for (i = 0; i < x; i++) {
    if (data[i].qimo > 80 && data[i].lunwen >= 1) data[i].jiangjin += 8000;
    if (data[i].qimo > 85 && data[i].banyi > 80) data[i].jiangjin += 4000;
    if (data[i].qimo > 90) data[i].jiangjin += 2000;
    if (data[i].qimo > 85 && data[i].xibu[0] == 'Y') data[i].jiangjin += 1000;
    if (data[i].banyi > 80 && data[i].bangan[0] == 'Y') data[i].jiangjin += 850;
  }
  t = -1;
  tsum = 0;
  for (i = 0; i < x; i++) {
    tsum += data[i].jiangjin;
    if (t < data[i].jiangjin) {
      t = data[i].jiangjin;
      k = i;
    }
  }
  printf("%s\n%d\n%d\n", data[k].name, data[k].jiangjin, tsum);

  return 0;
}