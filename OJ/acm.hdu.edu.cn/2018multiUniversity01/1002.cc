#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

const int N = 1e5 + 10;

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        std::vector<std::string> s(n);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            static char buf[N];
            scanf("%s", buf);
            s[i] = buf;
            m = std::max<int>(m, s[i].size());
        }
        std::vector<std::pair<int, int>> left(m + 1), right(m + 1);
        int sum = 0, length = 0;
        for (int i = 0; i < n; ++i) {
            int mx = 0, d = 0;
            for (auto &&c : s[i]) {
                d += (c == '(' ? 1 : -1);
                if (d < mx) mx = d;
            }
            if (d >= 0) left[-mx].first += d, left[-mx].second = 1;
            else right[d - mx].first -= d, right[d - mx].second = 1;
            sum += d;
            length += s[i].size();
        }
        int suml = 0, minl = 0, sumr = 0, minr = 0;
        for (int i = 0; i <= m; ++i) {
            if (left[i].second) minl = std::min(minl, suml - i);
            suml += left[i].first;
            if (right[i].second) minr = std::min(minr, sumr - i);
            sumr += right[i].first;
        }
        printf("%d\n", length - sum + 2 * std::min(minl, minr + sum));
    }
    return 0;
}

