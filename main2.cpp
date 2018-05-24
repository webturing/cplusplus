#include <cstdio>
#include <cstdlib>
#include <ctime>

#define N 100
#define h(x) (1LL * (x) * (x) * (x) * (x) * (x))

int a, b, c, d, e, f;

void bad() {/**brute but fail!暴力枚举执行10000 00000
               0000次循环体!!!规模应该在好几天*/
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
void step1() {/**ok  using a<=b<=c<=d<=e<f to improve 执行1517381580次循环体*/
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

void step2() {/**function version 执行1517381580次循环体
                 函数版比宏版本稍快有点匪夷所思*/
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
            执行1517381580次循环体，数组版是一个很大的改进，避免了5次方的反复计算*/
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
                 ，结合二分查找，用logN代替一个循环也是一个很大的改进*/
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
                 ，改变了搜索顺序，假定f>a>=b>=c>=d>=e也可以优化很多，有趣*/
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
