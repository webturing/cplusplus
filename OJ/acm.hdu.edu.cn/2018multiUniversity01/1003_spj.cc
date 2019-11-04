#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using int64 = long long;

struct point {
    int64 x, y;

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

inline int sgn(int64 x) { return x < 0 ? -1 : x > 0; }

bool inside(const point &a, const point &b, const point &c, const point &o) {
    return std::abs((a - o).det(b - o)) + std::abs((b - o).det(c - o)) + std::abs((c - o).det(a - o)) ==
           std::abs((b - a).det(c - a));
}

bool intersect(const point &a, const point &b, const point &c, const point &d) {
    point ab(b - a), cd(d - c);
    return sgn(ab.det(c - a)) * sgn(ab.det(d - a)) < 0 && sgn(cd.det(a - c)) * sgn(cd.det(b - c)) < 0;
}

constexpr int _wa = 0;
constexpr int _ok = 0;

void quitf(int status, const char *s) {
    printf("%s\n", s);
    exit(status);
}

int main(int argc, char **argv) {
    FILE *fin = fopen(argv[1], "r");
    int T;
    fscanf(fin, "%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        fscanf(fin, "%d", &n);
        std::vector<point> p(n * 3);
        for (int i = 0; i < n * 3; ++i) {
            fscanf(fin, "%lld%lld", &p[i].x, &p[i].y);
        }
        std::vector<bool> mark(n * 3);
        std::vector<point> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            --x, --y, --z;
            if (x < 0 || x >= n * 3) quitf(_wa, "range error");
            if (y < 0 || y >= n * 3) quitf(_wa, "range error");
            if (z < 0 || z >= n * 3) quitf(_wa, "range error");
            if (mark[x]) quitf(_wa, "duplicate index");
            mark[x] = 1;
            if (mark[y]) quitf(_wa, "duplicate index");
            mark[y] = 1;
            if (mark[z]) quitf(_wa, "duplicate index");
            mark[z] = 1;
            a[i] = p[x], b[i] = p[y], c[i] = p[z];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (inside(a[i], b[i], c[i], a[j])) quitf(_wa, "inside");
                if (inside(a[i], b[i], c[i], b[j])) quitf(_wa, "inside");
                if (inside(a[i], b[i], c[i], c[j])) quitf(_wa, "inside");
                if (i < j) {
                    if (intersect(a[i], b[i], a[j], b[j])) quitf(_wa, "intersect");
                    if (intersect(a[i], b[i], b[j], c[j])) quitf(_wa, "intersect");
                    if (intersect(a[i], b[i], c[j], a[j])) quitf(_wa, "intersect");
                    if (intersect(b[i], c[i], a[j], b[j])) quitf(_wa, "intersect");
                    if (intersect(b[i], c[i], b[j], c[j])) quitf(_wa, "intersect");
                    if (intersect(b[i], c[i], c[j], a[j])) quitf(_wa, "intersect");
                    if (intersect(c[i], a[i], a[j], b[j])) quitf(_wa, "intersect");
                    if (intersect(c[i], a[i], b[j], c[j])) quitf(_wa, "intersect");
                    if (intersect(c[i], a[i], c[j], a[j])) quitf(_wa, "intersect");
                }
            }
        }
    }
    quitf(_ok, "AC");
    return 0;
}
