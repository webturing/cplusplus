#include<bits/stdc++.h>

using namespace std;
int no = 0;

void f(int n, char A, char B, char C) {
    if (n == 1) {
        printf("%d.Move %d from %c to %c\n", ++no, n, A, C);
        return;
    }
    f(n - 1, A, C, B);
    printf("%d.Move %d from %c to %c\n", ++no, n, A, C);
    f(n - 1, B, A, C);
    return;
}


int main(void) {
    int n;
    cin >> n;
    f(n, 'a', 'b', 'c');
    return 0;
}