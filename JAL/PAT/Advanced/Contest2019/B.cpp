#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int addr, val, next;
};
int main(){
    int addr1, addr2, n;
    scanf("%d %d %d", &addr1, &addr2, &n);// 怕T，用scanf
    map<int, Node>M;
    for(int i = 0; i < n; i++){
        int addr, val, next;
        scanf("%d %d %d", &addr, &val, &next);
        M[addr] = {addr, val, next};
    }
    vector<Node>v1, v2, v3;// v1 v2表示两个链表，v3表示最后合并的结果链表
    int p = addr1;
    while(p != -1){
        v1.push_back(M[p]);
        p = M[p].next;
    }
    p = addr2;
    while(p != -1){
        v2.push_back(M[p]);
        p = M[p].next;
    }
    // 使用用v1表示更长的那个链表，v2表示短的链表
    if(v1.size() < 2*v2.size()){
        swap(v1, v2);
    }
    reverse(v2.begin(), v2.end());// 翻转短链表
    for(int i = 0; i < v2.size(); i++){
        // 直接模拟插入到一个新链表即可。这样操作最简单不容易错
        v3.push_back(v1[2*i]);
        v3.push_back(v1[2*i+1]);
        v3.push_back(v2[i]);
    }
    for(int i = 2*v2.size(); i < v1.size(); i++){
        v3.push_back(v1[i]);
    }
    cout << v3.size() << endl;// 这里要输出长度吗，我也不记得了。。
    for(int i = 0; i < v3.size()-1; i++){
        printf("%05d %d %05d\n", v3[i].addr, v3[i].val, v3[i].next);
    }
    printf("%05d %d -1\n", v3.back().addr, v3.back().val);
}
