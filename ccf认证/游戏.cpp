#include<iostream>
#include<list>
#include<cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    int left = n;
    int arr[1000];
    for (int j = 0; j <= 1000; j++)
        arr[j] = -1;
    int i = 0;
    while (left > 1) {
        i = i % n;
        while (arr[i] == 0)//找到应该报数的小盆友
        {
            i++;
            i = i % n;
        }
        cnt++;//报数

        //cout<<"小盆友"<<i+1<<" 报数"<<cnt<<endl;

        if (cnt >= k && cnt % k == 0 || cnt % 10 == k)//判断是否出局
        {
            arr[i] = 0;
            left--;
            //cout<<"小盆友"<<i+1<<"出局"<<endl;
        }
        i++;//轮到下一个小朋友
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
} 
