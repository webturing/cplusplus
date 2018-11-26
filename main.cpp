#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define LL long long
#define writeln(x) printf("%d\n",x)
#define write(x) printf("%d",x)
#define PI acos(-1.0)

int main() {
    double r,h;
    scanf("%lf%lf",&r,&h);
    printf("Area=%.3f\n",2*PI*r*r+2*PI*r*h);
    return 0;
}