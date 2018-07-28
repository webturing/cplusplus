#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        if (n % 3 == 0) printf("%lld\n", 1ll * n * n * n / 27);
        else if (n % 4 == 0) printf("%lld\n", 1ll * n * n * n / 32);
        else puts("-1");
    }
    return 0;
}
