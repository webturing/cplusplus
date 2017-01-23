#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int length, diameter, number;
} PIPE;

int cmp(const void *a, const void *b) {
  PIPE *pa = (PIPE *)a, *pb = (PIPE *)b;
  int dlen = pb->length - pa->length;
  if (dlen) return dlen;
  int ddia = pa->diameter - pb->diameter;
  if (ddia) return ddia;
  return pb->number - pa->number;
}

void input(PIPE *p) { scanf("%d%d%d", &p->length, &p->diameter, &p->number); }

PIPE p[1000];
int N, m, i;

int main() {
  for (scanf("%d", &N); N-- && scanf("%d", &m);) {
    for (i = 0; i < m; i++) input(p + i);
    qsort(p, m, sizeof(p[0]), cmp);
    printf("%d\n", p[0].number);
  }
  return 0;
}
