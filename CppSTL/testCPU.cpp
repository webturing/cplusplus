#include <cstdio>
#include <cstdlib>
#include <ctime>

#define N 100
#define h(x) (1LL * (x) * (x) * (x) * (x) * (x))

int a, b, c, d, e, f;

void bad() {/**brute but fail!??????????10000 00000
               0000???????!!!????????¨¹???*/
  for (a = 1; a <= N; a++)
    for (b = 1; b <= N; b++)
      for (c = 1; c <= N; c++)
        for (d = 1; d <= N; d++)
          for (e = 1; e <= N; e++)
            for (f = 1; f <= N; f++)
              if (h(a) + h(b) + h(c) + h(d) + h(e) == h(f))
                printf("%d^5+%d^5+%d^5+%d^5+%d^5=%d^5\n", a, b, c, d, e, f);
}

/////////////////////////////////////////////////
void step1() {/**ok  using a<=b<=c<=d<=e<f to improve ???1517381580???????*/
  puts("Step1:macro");
  for (a = 1; a <= N; a++)
    for (b = a; b <= N; b++)
      for (c = b; c <= N; c++)
        for (d = c; d <= N; d++)
          for (e = d; e <= N; e++)
            for (f = e + 1; f <= N; f++)
              if (h(a) + h(b) + h(c) + h(d) + h(e) == h(f))
                printf("%d^5+%d^5+%d^5+%d^5+%d^5=%d^5\n", a, b, c, d, e, f);
}

//////////////////////////////////////////////////////////
long long hh(int x) { return 1LL * x * x * x * x * x; }

void step2() {/**function version ???1517381580???????
                 ????????·Ú????§Ö???????*/
  puts("Step2:function version");
  for (a = 1; a <= N; a++)
    for (b = a; b <= N; b++)
      for (c = b; c <= N; c++)
        for (d = c; d <= N; d++)
          for (e = d; e <= N; e++)
            for (f = e + 1; f <= N; f++)
              if (hh(a) + hh(b) + hh(c) + hh(d) + hh(e) == hh(f))
                printf("%d^5+%d^5+%d^5+%d^5+%d^5=%d^5\n", a, b, c, d, e, f);
}

/////////////////////////////////////////////////////////
long long H[1 + N] = {0LL};

void fill() {
  int i;
  for (i = 1; i <= N; i++) H[i] = 1LL * i * i * i * i * i;
}

void
step3() {/**array version
            ???1517381580??????ÈÉ????????????????????????5?¦Ç??????????*/
  puts("Step3: array version");
  fill();
  for (a = 1; a <= N; a++)
    for (b = a; b <= N; b++)
      for (c = b; c <= N; c++)
        for (d = c; d <= N; d++)
          for (e = d; e <= N; e++)
            for (f = e; f <= N; f++)
              if (H[a] + H[b] + H[c] + H[d] + H[e] == H[f])
                printf("%d^5+%d^5+%d^5+%d^5+%d^5=%d^5\n", a, b, c, d, e, f);
}

///////////////////////////////////////////////////////
long long k, *p;

int cmp(const void *a, const void *b) {
  long long flag = *(long long *)a - *(long long *)b;
  if (flag > 0) return 1;
  if (flag < 0) return -1;
  return 0;
}

void step4() {/**array_bsearch1 version
                 ??????????????logN??????????????????????*/
  puts("Step4:array +bsearch");
  fill();
  for (a = 1; a < N; a++)
    for (b = a; b < N; b++)
      for (c = b; c < N; c++)
        for (d = c; d < N; d++)
          for (e = d; e < N; e++) {
            k = H[a] + H[b] + H[c] + H[d] + H[e];
            p = (long long *)bsearch(&k, H + e + 1, (size_t)(N - e),
                                     sizeof(H[0]), cmp);
            if (p)
              printf("%d^5+%d^5+%d^5+%d^5+%d^5=%d^5\n", a, b, c, d, e,
                     f = (int)(p - H));
          }
}

/////////////////////////////////////
void step5() {/**array_bsearch2 version
                 ????????????????f>a>=b>=c>=d>=e??????????????*/
  puts("Step5:array +bsearch2");
  fill();
  for (a = 1; a < N; a++)
    for (b = 1; b <= a; b++)
      for (c = 1; c <= b; c++)
        for (d = 1; d <= c; d++)
          for (e = 1; e <= d; e++) {
            k = H[a] + H[b] + H[c] + H[d] + H[e];
            p = (long long *)bsearch(&k, H + a + 1, (size_t)(N - a),
                                     sizeof(H[0]), cmp);
            if (p)
              printf("%d^5+%d^5+%d^5+%d^5+%d^5=%d^5\n", e, d, b, c, a,
                     f = (int)(p - H));
          }
}

int main() {
  long long start, end;
  start = clock();
  step5();
  end = clock();
  printf("Total elapsed %.3f second(s)\n", (end - start) / 1000.0);
  start = clock();
  step4();
  end = clock();
  printf("Total elapsed %.3f second(s)\n", (end - start) / 1000.0);
  start = clock();
  step3();
  end = clock();
  printf("Total elapsed %.3f second(s)\n", (end - start) / 1000.0);
  start = clock();
  step2();
  end = clock();
  printf("Total elapsed %.3f second(s)\n", (end - start) / 1000.0);
  start = clock();
  step1();
  end = clock();
  printf("Total elapsed %.3f second(s)\n", (end - start) / 1000.0);
  start = clock();
  bad();
  end = clock();
  printf("Total elapsed %.3f second(s)\n", (end - start) / 1000.0);
  return 0;
}
