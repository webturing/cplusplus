#include <cstdio>
#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>

using int64 = long long;
using strings = std::vector<std::pair<int, int>>;

const int N = 1e6 + 10;

char s[N], buf[N];

template<class T, class Compare = std::less<T>>
class SchieberVishkinRMQ {
public:
    SchieberVishkinRMQ() = default;

    void build(const std::vector<T> &a) {
        build(a.data(), a.size());
    }

    void build(const T *a, int n) {
        std::vector<int> left(n, -1), right(n, -1);
        std::vector<int> stk(n);
        // build Cartesian Tree
        for (int i = 0, top = 0; i < n; ++i) {
            int last = -1;
            while (top && compare(a[i], a[stk[top - 1]])) {
                last = stk[--top];
            }
            if (top) right[stk[top - 1]] = i;
            left[i] = last;
            stk[top++] = i;
        }

        // find preorder
        int root = stk[0];
        std::vector<int> parents(n, -1), order;
        indices.resize(n), inlabel.resize(n);
        for (int top = 1; top;) {
            int u = stk[--top];
            order.push_back(u);
            indices[u] = inlabel[u] = order.size();
            if (left[u] != -1) {
                stk[top++] = left[u];
                parents[left[u]] = u;
            }
            if (right[u] != -1) {
                stk[top++] = right[u];
                parents[right[u]] = u;
            }
        }

        // calc helper structures for Schieber-Vishkin LCA
        ascendant.resize(n), head.resize(n);
        for (int i = n - 1; i > 0; --i) {
            int v = order[i], p = parents[v];
            if (lowbit(inlabel[p]) < lowbit(inlabel[v])) {
                inlabel[p] = inlabel[v];
            }
        }
        ascendant[root] = 0;
        for (int i = 1; i < n; ++i) {
            int v = order[i], p = parents[v];
            ascendant[v] = ascendant[p] | lowbit(inlabel[v]);
        }
        head[0] = root;
        for (int i = 1; i < n; ++i) {
            int v = order[i], p = parents[v];
            if (inlabel[v] != inlabel[p]) head[indices[v] - 1] = p;
            else head[indices[v] - 1] = head[indices[p] - 1];
        }
    }

    // return the index of the minimum value in [u, v] in O(1)
    int query(int u, int v) const {
        uint Iv = inlabel[v], Iu = inlabel[u];
        uint hIv = lowbit(Iv), hIu = lowbit(Iu);
        uint mask = highbit((Iv ^ Iu) | hIv | hIu) - 1;
        uint j = lowbit(ascendant[v] & ascendant[u] & ~mask);
        int x, y;
        if (j == hIv) x = v;
        else {
            mask = highbit(ascendant[v] & (j - 1)) - 1;
            x = head[((indices[v] & ~mask) | (mask + 1)) - 1];
        }
        if (j == hIu) y = u;
        else {
            mask = highbit(ascendant[u] & (j - 1)) - 1;
            y = head[((indices[u] & ~mask) | (mask + 1)) - 1];
        }
        return indices[x] < indices[y] ? x : y;
    }

private:
    using uint = unsigned int;

    static uint lowbit(uint x) {
        return x & (~x + 1); // x & (-x) or x & (x ^ (x - 1))
    }

    static uint highbit(uint x) {
        return 1u << (31 - __builtin_clz(x));
    }

    Compare compare;
    std::vector<uint> indices;
    std::vector<uint> inlabel;
    std::vector<uint> ascendant;
    std::vector<int> head;
};

#define pushS(x) sa[--cur[(int)s[x]]] = x
#define pushL(x) sa[cur[(int)s[x]]++] = x

class SuffixArray {
public:
    std::vector<int> sa;
    std::vector<int> rank;
    std::vector<int> lcp;
    SchieberVishkinRMQ<int> lcpRMQ;

    template<class T>
    void build(const T *s, int n);

    template<class T>
    void build(const T *s, int n, int m);

    int size() const {
        return sa.size() - 1;
    }

    int computeLCP(int i, int j) const {
        if (i == j) return size() - i;
        int x = rank[i], y = rank[j];
        if (x > y) std::swap(x, y);
        return lcp[lcpRMQ.query(x + 1, y)];
    }

private:
    using SLTypes = std::vector<bool>;
    int *buffer, *freq, *cur;
    int len;

    void buildRankTable();

    void buildLCPArrayRMQ();

    template<class T>
    void computeLCPArray(const T *s);

    template<class T>
    void countFrequency(const T *s, int n, int m);

    template<class T>
    void induce(const T *s, int *sa, int m, const SLTypes &t);

    template<class T>
    void sa_is(const T *s, int *sa, int n, int m);
};

template<class T>
void SuffixArray::build(const T *s, int n) {
    this->len = n;
    int m = *std::max_element(s, s + n) + 1;
    build(s, n, m);
    buildRankTable();
    computeLCPArray(s);
    buildLCPArrayRMQ();
}

template<class T>
void SuffixArray::build(const T *s, int n, int m) {
    sa.resize(n + 1);
    if (n == 0) sa[0] = 0;
    else {
        // memory usage: sa + buffer + types
        // = 4 * (n + max(m * 2, n)) + 2 * n / 8 + O(1) bytes
        std::vector<int> buffer((std::max(m, (n + 1) / 2) + 1) * 2);
        this->buffer = &buffer[0];
        sa_is<T>(s, &sa[0], n + 1, m);
    }
}

void SuffixArray::buildRankTable() {
    int n = size() + 1;
    rank.resize(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
}

void SuffixArray::buildLCPArrayRMQ() {
    lcpRMQ.build(&lcp[0], size() + 1);
}

template<class T>
void SuffixArray::computeLCPArray(const T *s) {
    const int n = size() + 1;
    lcp.resize(n);
    for (int i = 0, h = lcp[0] = 0; i < n; ++i) {
        if (!rank[i]) continue;
        int j = sa[rank[i] - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
        if ((lcp[rank[i]] = h)) --h;
    }
}

template<class T>
void SuffixArray::countFrequency(const T *s, int n, int m) {
    memset(freq, 0, sizeof(int) * m);
    for (int i = 0; i < n; ++i) ++freq[(int) s[i]];
    for (int i = 1; i < m; ++i) freq[i] += freq[i - 1];
    memcpy(cur, freq, sizeof(int) * m);
}

template<class T>
void SuffixArray::induce(const T *s, int *sa, int m, const SLTypes &t) {
    const int n = t.size();
    memcpy(cur + 1, freq, sizeof(int) * (m - 1));
    for (int i = 0; i < n; ++i) {
        int p = sa[i] - 1;
        if (p >= 0 && t[p]) pushL(p);
    }
    memcpy(cur, freq, sizeof(int) * m);
    for (int i = n - 1; i > 0; --i) {
        int p = sa[i] - 1;
        if (p >= 0 && !t[p]) pushS(p);
    }
}

template<class T>
void SuffixArray::sa_is(const T *s, int *sa, int n, int m) {
    SLTypes t(n);
    memset(sa, 0, sizeof(int) * n);
    for (int i = n - 2; ~i; --i) {
        t[i] = (s[i] == s[i + 1]) ? t[i + 1] : s[i] > s[i + 1];
    }
    freq = buffer, cur = buffer + m;
    countFrequency(s, n, m);
    for (int i = 1; i < n; ++i) if (t[i - 1] > t[i]) pushS(i);
    induce(s, sa, m, t);
    int n1 = 0, order = 0;
    for (int i = 0, p; i < n; ++i) {
        if ((p = sa[i]) && t[p - 1] > t[p]) sa[n1++] = p;
    }
    int *s1 = sa + n1;
    memset(s1, -1, sizeof(int) * (n - n1));
    s1[(sa[0] - 1) / 2] = order++;
    for (int i = 1; i < n1; ++i) {
        bool diff = true;
        for (int x = sa[i - 1], y = sa[i];; ++x, ++y) {
            if (s[x] != s[y] || t[x] != t[y]) break;
            else if (t[x] > t[x + 1] && t[y] > t[y + 1]) {
                diff = (s[x + 1] != s[y + 1]);
                break;
            }
        }
        s1[(sa[i] - 1) / 2] = (order += diff) - 1;
    }
    for (int i = 0, x = 0; i < n - n1; ++i) {
        if (~s1[i]) s1[x++] = s1[i];
    }
    if (order != n1) {
        sa_is<int>(s1, sa, n1, order);
        for (int i = 0; i < n1; ++i) s1[sa[i]] = i;
    }
    for (int i = 1, j = 0; i < n; ++i) {
        if (t[i - 1] > t[i]) sa[s1[j++]] = -i;
    }
    memset(s1, 0, sizeof(int) * (n - n1));
    freq = buffer, cur = buffer + m;
    countFrequency(s, n, m);
    for (int i = n1 - 1; ~i; --i) pushS(-sa[i]);
    induce(s, sa, m, t);
}

std::vector<int> duval(const char s[]) {
    std::vector<int> ret;
    int n = strlen(s) + 1; // zero used here
    int start = 0, mid = 1, cur = 0;
    ret.push_back(0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[cur]) {
            if (++cur == mid) cur = start;
        } else if (s[i] > s[cur]) {
            mid = i + 1;
            cur = start;
        } else if (s[i] < s[cur]) {
            int temp = mid - start;
            while (start + temp <= i) {
                start += temp;
                ret.push_back(start);
            }
            i = cur = start;
            mid = start + 1;
        }
    }
    return ret;
}

struct lyndon_t {
    int s, l, k;
    int prefix, suffix;

    lyndon_t(int a, int b, int c) : s(a), l(b), k(c) {
        prefix = suffix = l;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n, m;
        scanf("%d%d", &n, &m);
        std::vector<int> offset(n + 1);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s + offset[i]);
            offset[i + 1] = offset[i] + strlen(s + offset[i]);
        }
        SuffixArray sa;
        sa.build(s, offset[n]);

        // compare s[a..b] and s[c..d]
        auto compare = [&](int a, int b, int c, int d) {
            int lcp = sa.computeLCP(a, c);
            lcp = std::min(lcp, b - a + 1);
            lcp = std::min(lcp, d - c + 1);
            for (int i = 0; i < lcp; ++i) assert(s[a + i] == s[c + i]);
            char x = a + lcp <= b ? s[a + lcp] : 0;
            char y = c + lcp <= d ? s[c + lcp] : 0;
            /*
            printf("(%d %d) (%d %d)\n", a, b, c, d);
            printf("xxxx lcp=%d %d %d\n", lcp, int(x), int(y));*/
            return x - y;
        };

        auto compare2 = [&](std::vector<std::pair<int, int>> a, std::vector<std::pair<int, int>> b) -> int {
            /*
            std::string x = "", y = "";
            for (auto &&e: a) for (int i = e.first; i <= e.second; ++i) x += s[i];
            for (auto &&e: b) for (int i = e.first; i <= e.second; ++i) y += s[i];
            //printf("%s %s\n", x.c_str(), y.c_str());
            if (x == y) return 0;
            if (x < y) return -1;
            return 1;*/
            int n = a.size(), m = b.size();
            int i = 0, j = 0;
            while (i < n && j < m) {
                int lcp = sa.computeLCP(a[i].first, b[j].first);
                int la = a[i].second - a[i].first + 1;
                int lb = b[j].second - b[j].first + 1;
                lcp = std::min(lcp, std::min(la, lb));
                if (lcp < la && lcp < lb) {
                    return s[a[i].first + lcp] - s[b[j].first + lcp];
                } else if (lcp == la && lcp < lb) {
                    ++i;
                    b[j].first += lcp;
                } else if (lcp < la && lcp == lb) {
                    ++j;
                    a[i].first += lcp;
                } else {
                    ++i, ++j;
                }
            }
            if (i != n) return 1;
            else if (j != m) return -1;
            else return 0;
        };

        std::vector<std::vector<lyndon_t>> lf(n);
        for (int i = 0; i < n; ++i) {
            memcpy(buf, s + offset[i], sizeof(char) * (offset[i + 1] - offset[i]));
            buf[offset[i + 1] - offset[i]] = 0;
            auto u = duval(buf);
            for (size_t j = 1, k; j < u.size(); j = k) {
                int l = offset[i] + u[j - 1], r = offset[i] + u[j] - 1;
                for (k = j; k < u.size(); ++k) {
                    int x = offset[i] + u[k - 1], y = offset[i] + u[k] - 1;
                    if (compare(l, r, x, y) != 0) break;
                }
                lf[i].push_back(lyndon_t(offset[i] + u[j - 1], u[j] - u[j - 1], k - j));
            }
            for (size_t j = 1; j < lf[i].size(); ++j) {
                lf[i][j].prefix = std::max(lf[i][j].prefix, lf[i][j - 1].prefix);
            }
            for (int j = lf[i].size() - 2; j >= 0; --j) {
                lf[i][j].suffix = std::max(lf[i][j].suffix, lf[i][j + 1].suffix);
            }
        }

        for (int it = 0; it < m; ++it) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            const auto &lfx = lf[x];
            const auto &lfy = lf[y];
            auto u = lfx.back();
            auto v = lfy[0];
            int a = u.s, b = u.s + u.l - 1;
            int c = v.s, d = v.s + v.l - 1;
            auto res = compare(a, b, c, d);
            /*
            for (auto &&e: lfx) printf("%d %d %d\n", e.s, e.l, e.k);
            puts("");
            for (auto &&e: lfy) printf("%d %d %d\n", e.s, e.l, e.k);
            puts("");
            printf("%d\n", res);*/
            if (res >= 0) {
                printf("%d\n", std::max(u.prefix, v.suffix));
            } else {
                strings left, right;
                int l = 0, r = lfx.size() - 1;
                while (l < r) {
                    int m = (l + r - 1) >> 1;
                    left = {{lfx[m].s,  offset[x + 1] - 1},
                            {offset[y], offset[y + 1] - 1}};
                    if (m == lfx.size() - 1) right = {{offset[y], offset[y + 1] - 1}};
                    else
                        right = {{lfx[m + 1].s, offset[x + 1] - 1},
                                 {offset[y],    offset[y + 1] - 1}};
                    if (compare2(left, right) < 0) r = m;
                    else l = m + 1;
                }
                int ret = 0;
                if (r > 0) ret = std::max(ret, lfx[r - 1].prefix);
                int ext = offset[x + 1] - lfx[r].s;
                left = {{lfx[r].s,  offset[x + 1] - 1},
                        {offset[y], offset[y + 1] - 1}};
                l = 0, r = lfy.size();
                while (l < r) {
                    int m = (l + r - 1) >> 1;
                    if (m == lfy.size()) right = {};
                    else right = {{lfy[m].s, offset[y + 1] - 1}};
                    int res = compare2(left, right);
                    //printf("m = %d, res=%d\n", m, res);
                    if (res > 0) r = m;
                    else l = m + 1;
                }
                if (r != lfy.size()) {
                    ret = std::max(ret, lfy[r].suffix);
                    ext += lfy[r].s - offset[y];
                } else {
                    ext += offset[y + 1] - offset[y];
                }
                ret = std::max(ret, ext);
                printf("%d\n", ret);
            }
        }
    }
    return 0;
}
