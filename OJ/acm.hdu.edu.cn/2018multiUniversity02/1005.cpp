#include <stdio.h>

int P = 47, f[233333], an = 0, gg[2333][2333];

int main() {
    for (int i = 0; i < P; i++) {
        for (int r = 0; r < P; ++r) {
            ++an;
            for (int j = i, k = 0; k < P; k++, j = (j + r) % P)
                f[j * P + k] = an;
            for (int j = 0; j < P * P; ++j)
                if (f[j] == an) gg[i * P + r][j] = 1;
        }
    }
    printf("%d\n", 1999);
    for (int i = 0; i < 1999; ++i, puts(""))
        for (int j = 0; j < 1999; ++j)
            putchar(gg[i + 2][j + 2] + 48);
}
