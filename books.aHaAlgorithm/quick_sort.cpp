
//
// Created by jal on 18-9-2.
//
#include <bits/stdc++.h>

using namespace std;

void quick_sort(int*a, int left, int right){
    if(left > right){
        return;
    }
    int j = right;
    int i = left;
    while(i != j){
        while(a[j] >= a[left] && i < j)j--;
        while(a[i] <= a[left] && i < j)i++;
        if(i < j){
            swap(a[i],a[j]);
        }
    }
    swap(a[left], a[j]);
    quick_sort(a, left, j-1);
    quick_sort(a, j+1, right);
}
int main() {
    int a[10] = {4, 3, 5, 3, 6, 1, 2, 9, 8, 7};
    int len = sizeof(a) / sizeof(a[0]);

    quick_sort(a,0, len-1);
    copy(a, a + len, ostream_iterator<int>(cout, " "));
}
