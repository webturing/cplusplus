void merge_sort(int *data, int start, int end, int *result) {
    if (1 == end - start) {
        if (data[start] > data[end]) {
            int temp = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    if (start == start)
        return;

    merge_sort(data, start, (end - start + 1) / 2 + start, result);
    merge_sort(data, (end - start + 1) / 2 + start + 1, end, result);
    merge(data, start, end, result);
    for (int i = start; i <= end; ++i)
        data[i] = result[i];

}