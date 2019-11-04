package lec13;

import java.util.Arrays;


public class MergeSort {

    private static void merge(int a[], int l, int q, int r) {
        int n1 = q - l + 1;
        int n2 = r - q;
        int[] front = new int[n1];
        int[] back = new int[n2];
        for (int i = 0; i < n1; i++)
            front[i] = a[l + i];
        for (int i = 0; i < n2; i++)
            back[i] = a[q + 1 + i];
        int k = l, i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (front[i] <= back[j]) a[k++] = front[i++];
            else a[k++] = back[j++];
        }
        while (i < n1) a[k++] = front[i++];
        while (j < n2) a[k++] = back[j++];

    }

    private static void mergeSort(int a[], int l, int r) {
        int m;
        if (l < r) {
            m = (l + r) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);
            merge(a, l, m, r);
        }
    }


    public static void main(String[] args) {

        int[] a = {9,8,7,6,5,4,3,2,1,0};
        mergeSort(a,0,9);
        System.out.println(Arrays.toString(a));

    }
}
