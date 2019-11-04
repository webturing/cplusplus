#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n, L, t;
    cin >> n >> L >> t;

    int arr[105];
    int temp[105];    //用于存储arr排序的升序序列结果
    int index[105];    //用于存放升序序列中每个数原来的下标
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    //将小球位置进行排序，并记录每个数字原来的数组下标
    sort(temp, temp + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] == temp[i])
                index[i] = j;
        }
    }

    //计算每个小球经过t时间后的位置
    //小球之间相碰撞看做是交换位置继续往原来的方向移动
    //每个小球到L处就改变方向 向左运动，到0位置就改变方向 向右运动
    int flag = 1;//flag=1,go right,flag=0,go left
    for (int i = 0; i < n; i++) {
        flag = 1;
        for (int j = 0; j < t; j++) {
            if (flag)
                arr[i]++;
            else arr[i]--;
            if (arr[i] == L) flag = 0;
            else if (arr[i] == 0) flag = 1;
        }
    }

    //将最终结果进行排序
    sort(arr, arr + n);

    //由于每个小球的相对位置不会改变
    //因此，排序后的最终结果还原到对应原来index[]数组中的下标,利用temp[]来存放就好了
    for (int i = 0; i < n; i++) {
        temp[index[i]] = arr[i];
    }

    //输出结果
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    return 0;
} 
