/*
5 7
3 3 12
1 1 14
1 15 12
2 7 20
3 18 12
4 21 19
5 30 9
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[1005];
    for (int i = 1; i <= n; i++)
        arr[i] = i;

    int usekey[1005];
    int from[1005];
    int usetime[1005];
    int max = 0;

    for (int i = 0; i < k; i++) {
        cin >> usekey[i] >> from[i] >> usetime[i];

        if (from[i] + usetime[i] > max)
            max = from[i] + usetime[i];
    }

    int flag = 0;
    //cout<<"max="<<max<<endl;

    for (int i = 1; i <= max; i++) {
        int queue[1005];
        int r = 0;
        for (int j = 0; j < k; j++) {
            if (from[j] + usetime[j] == i) //是否此刻有还钥匙的
            {
                queue[r++] = usekey[j];
            }
        }
        sort(queue, queue + r);
        for (int i = 0; i < r; i++) {
            int k = 1;
            while (arr[k] != 0) k++;
            arr[k] = queue[i];
            flag = 1;
        }

        for (int j = 0; j < k; j++) {
            if (from[j] == i) //是否此刻有借钥匙，有的话借出钥匙 ,借出位置置为0
            {
                int k = 1;
                while (arr[k] != usekey[j]) k++;
                arr[k] = 0;
                flag = 1;
            }

        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
