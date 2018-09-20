#include <cstdio>
#include <cmath>
int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);
  double delta = b * b - 4 * a * c;
  if (delta > 0) {
    double x1 = (-b - sqrt(delta)) / (2 * a);
    double x2 = (-b + sqrt(delta)) / (2 * a);
    printf("%.4f %.4f\n", x1, x2);
  } else if (delta < 0) {
    puts("no answer");
  } else {
    printf("%.4f\n", -b / (2 * a));
  }
  return 0;
}