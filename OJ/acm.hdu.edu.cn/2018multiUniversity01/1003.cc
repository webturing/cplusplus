#include <cstdio>
#include <vector>

using int64 = long long;

struct point {
    int64 x, y;
    int i;

    point(int64 x = 0, int64 y = 0) : x(x), y(y) {}

    point operator+(const point &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    point operator-(const point &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    int64 det(const point &rhs) const {
        return x * rhs.y - y * rhs.x;
    }

    int64 dot(const point &rhs) const {
        return x * rhs.x + y * rhs.y;
    }
};

const int N = 5e3 + 10;

point p[N];

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        n *= 3;
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &p[i].x, &p[i].y);
            p[i].i = i + 1;
        }
        for (int it = 0; it < n / 3; ++it) {
            int m = n - it * 3;
            int a = 0, b = -1, c = -1;
            // lowest point p_a
            for (int i = 1; i < m; ++i) {
                if (p[i].y < p[a].y || (p[i].y == p[a].y && p[i].x < p[a].x)) a = i;
            }
            // right most point p_b
            for (int i = 0; i < m; ++i)
                if (i != a) {
                    if (b == -1 || (p[b] - p[a]).det(p[i] - p[a]) < 0) b = i;
                }
            // second right most point p_c
            for (int i = 0; i < m; ++i)
                if (i != a && i != b) {
                    if (c == -1 || (p[c] - p[a]).det(p[i] - p[a]) < 0) c = i;
                }
            printf("%d %d %d\n", p[a].i, p[b].i, p[c].i);
            for (int i = 0, j = 0; i < m; ++i)
                if (i != a && i != b && i != c) {
                    p[j++] = p[i];
                }
        }
    }
    return 0;
}
