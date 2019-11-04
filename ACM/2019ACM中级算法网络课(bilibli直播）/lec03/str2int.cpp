#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 123456, m; //m=612345;
    char buffer[100];
    //printf("%d%d", n % 10, n / 10);
    sprintf(buffer, "%d%d", n % 10, n / 10);//int2str
    //scanf("%d", &m);
    sscanf(buffer, "%d", &m);//str2int atoi/itoa 不是ASCI C的标准API
    printf("%d\n", m);

}
