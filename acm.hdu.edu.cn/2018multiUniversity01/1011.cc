#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int sgn;
        int a, b, x, y(0);
        std::string s;
        std::cin >> a >> b >> s;
        sgn = (s[3] == '+' ? 1 : -1);
        s = s.substr(4);
        if (s.size() > 2) {
            y = s.back() - '0';
            s.pop_back();
            s.pop_back();
        }
        x = std::stoi(s);

        int m = (a + 24) * 60 + b;

        int c = 80;
        int d = sgn * (x * 10 + y);
        int e = d - c;
        int f = e * 6;
        int g = (m + f) % 1440;

        printf("%02d:%02d\n", g / 60, g % 60);
    }
    return 0;
}
