#include <iostream>

#define M 1000000
using namespace std;
int q[M];

void work(int a, int n) {
    q[1] = a;
    int two = 1, three = 1, rear = 2;
    while (rear <= n) {
        long long t1 = 2 * q[two] + 1, t2 = 3 * q[three] + 1;
        long long t = min(t1, t2);
        if (t1 < t2)
            two++;
        else
            three++;
        if (t != q[rear - 1])
            q[rear++] = t;
    }
    cout << q[n] << endl;
}

int main() {
    int a, n;
    while (cin >> a >> n)
        work(a, n);
    return 0;
}
