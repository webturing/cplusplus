#include<cstdio>
#include<algorithm>
#include<iterator>


int main() {
    std::vector<int> v(10);
    for (auto &i:v)scanf("%d", &i);
    std::sort(v.begin(), v.end());
    for (auto &i:v)printf("%d ", v[i]);
    printf("\n");
    return 0;
}
