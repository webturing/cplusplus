
//
// Created by jal on 18-9-2.
//
#include <bits/stdc++.h>

using namespace std;

int partion(int *a,int left,int right){
    int key = a[left];
    int i = left;
    for(int j = i+1; j <= right; j++){
        if(a[j] < key){
            swap(a[i+1], a[j]);
            i++;
        }
    }
    swap(a[left], a[i]);
    return i;
}

void quick_sort(int*a, int left, int right){
    if(left >= right){
        return;
    }
    int p = partion(a, left, right);
    quick_sort(a, left, p-1);
    quick_sort(a, p+1, right);
}


int main() {
    int a[10] = {4, 3, 5, 3, 6, 1, 2, 9, 8, 7};
    int len = sizeof(a) / sizeof(a[0]);

    quick_sort(a,0, len-1);
    copy(a, a + len, ostream_iterator<int>(cout, " "));
}
