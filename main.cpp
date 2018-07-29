#include <bits/stdc++.h>

using namespace std;

int n,x,y;

struct Fraction{
    int up,down;
    Fraction operator+(Fraction that){
        Fraction ret;
        ret.down = down * that.down;
        ret.up = down * that.up + up * that.down;
    }
};
int getMinSwaps(vector<int> &nums){
    //排序
    vector<int> nums1(nums);
    sort(nums1.begin(),nums1.end());
    unordered_map<int,int> m;
    int len = nums.size();
    for (int i = 0; i < len; i++){
        m[nums1[i]] = i;//建立每个元素与其应放位置的映射关系
    }

    int loops = 0;//循环节个数
    vector<bool> flag(len,false);
    //找出循环节的个数
    for (int i = 0; i < len; i++){
        if (!flag[i]){//已经访问过的位置不再访问
            int j = i;
            while (!flag[j]){
                flag[j] = true;
                j = m[nums[j]];//原序列中j位置的元素在有序序列中的位置
            }
            loops++;
        }
    }
    return len - loops;
}

int cnt;
int arr[1005];
void Merge(int* arr,int* tmp,int left,int right,int rightEnd){
    int leftEnd = right - 1;
    int start = left;
    while (left <= leftEnd && right <= rightEnd){
        if (arr[left] > arr[right]){
            tmp[start++] = arr[right++];
            cnt += (leftEnd - left+1); //如果当前left位置上的数大于right位置上的数，那么从left到leftEnd所有的数都大于
        }
        else{
            tmp[start++] = arr[left++];
        }
    }
    while (left <= leftEnd){
        tmp[start++] = arr[left++];
    }
    while (right <= rightEnd){
        tmp[start++] = arr[right++];
    }
}
void MergeSort(int* arr,int* tmp,int n,int length)//length当前有序子列的长度
{
    int i;
    for (i = 0; i <= n - 2 * length; i += 2 * length){
        Merge(arr,tmp,i,i+length,i+2*length-1);
    }
    //最后剩下两个子列，进行归并
    if (i + length < n){
        Merge(arr,tmp,i,i+length,n-1);
    }
    else{//只剩最后一个子列，不能成对
        for (int j = i; j < n; j++){
            tmp[j] = arr[j];
        }
    }
}
void Merge_Sort(int* arr,int n){
    int lenght = 1;
    int* tmp = (int *)malloc(sizeof(int)*n);
    while (lenght < n){
        MergeSort(arr,tmp,n,lenght);
        lenght *= 2;
        MergeSort(tmp,arr,n,lenght);
        lenght *= 2;
    }
    free(tmp);
}
int main(){
    while(cin >> n >> x >> y){
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            arr[i] = v[i];
        }
        int first = getMinSwaps(v);
        cout << "first:"<<first << endl;
        first *= x;
        cnt=0;
        Merge_Sort(arr,n);
        int second = cnt;
        cout << "second:"<<second << endl;
        second *= y;
        cout << min(first, second) << endl;
    }

}