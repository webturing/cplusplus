#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x, y, s;
};
int next_dir[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0}};
int main(){
    int n, m;
    cin >> n >> m;
    int a[n+1][m+1], book[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            book[i][j] = 0;
        }
    }
    int x_1, y_1, x_2, y_2;
    cin >> x_1>>y_1>>x_2>>y_2;
    Node s={x_1, y_1, 0};
    queue<Node>q;
    book[x_1][y_1] = 1;
    q.push(s);
    int flag = 0;
    int cnt = 0;
    while(q.size() > 0){// queue is not empty
        Node head = q.front();// head is queue's head
        if(head.x == x_2 && head.y == y_2){
            flag = 1;
            cnt = head.s;
            break;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int tx = head.x + next_dir[i][0];
            int ty = head.y + next_dir[i][1];
            if(tx <= 0 || tx > n || ty <= 0 || ty > m || a[tx][ty] == 1 || book[tx][ty] == 1)continue;
            Node temp={tx, ty, head.s+1};
            book[tx][ty] = 1;
            q.push(temp);
        }
    }
    if(flag){
        cout << cnt << endl;
    }else{
       cout << "no way" << endl;
    }
}
