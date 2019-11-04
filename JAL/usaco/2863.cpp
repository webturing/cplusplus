#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <cstdio>
#include <string>
#include <vector>
#include <map>

using LL=long long;

#define FOR(i, x, y) for (std::decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (std::decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)


int main() {
    //  freopen("test.in","r",stdin);
    int np;
    scanf("%d", &np);
    std::vector<std::string> persons(np);
    std::map<std::string, int> mp;
    for (auto &person : persons) {
        person.resize(100);
        scanf("%s", &person[0]);
        mp[person] = 0;
    }
    FOR(i, 0, np) {
        std::string sender;
        sender.resize(100);
        int amount, ng;
        scanf("%s%d%d", &sender[0], &amount, &ng);

        if (amount == 0 && ng == 0) continue;
        amount /= ng;
        FOR(j, 0, ng) {
            std::string reciever;
            reciever.resize(100);
            scanf("%s", &reciever[0]);
            mp[reciever] += amount;
            mp[sender] -= amount;
        }
    }
    for (auto person : persons) printf("%s %d\n", person.c_str(), mp[person]);
    return EXIT_SUCCESS;
}