#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int N = 1e5 + 100;

double x_, y_, sx, sy;
double x[N], y[N];

int main() {
    int n, k, t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d%d", &n, &k);
        sx = sy = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", x + i, y + i);
            sx += x[i];
            sy += y[i];
        }
        x_ = sx / (double) n;
        y_ = sy / (double) n;
        double fz = 0, fm = 0;
        for (int i = 0; i < n; ++i) {
            double tmp = x[i] - x_;
            fz += tmp * (y[i] - y_);
            fm += tmp * tmp;
        }
        printf("%lf %lf\n", fz / fm, y_ - (fz / fm) * x_);
    }
    return 0;
}