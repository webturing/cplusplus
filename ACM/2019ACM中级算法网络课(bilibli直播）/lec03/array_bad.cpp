#include<stdio.h>

using namespace std;
const int MAXN = 1000;
int a[MAXN];

int main() {

    int *p = (int *) malloc(sizeof(int) * 100000);
    if (p != NULL) {
        //开辟成功
    } else {
        //申请失败
    }
    free(p);
    int *q = new int[1000];
    //
    free(q);//释放内存

    return 0;
}