# 第一讲：排序查找、各种排序的实现

## 1. 数组排序和查找

### 比较器
### qsort比较函数
```C++
int cmp(const void*a,const void*b){
    int* ia=(int*)a;
    int* ib=(int*)b;
    return *ia-*ib;
}
```
### sort比较函数
```c++
bool cmp(int a,int b){return a<b;}

```
## 2. 二分查找

### C++二分查找函数
- bsearch
- binary_search
- lower_bound
- upper_bound
- equal_range

### 二分查找法的应用

- 高效计数

- count O(n)

- upper_bound/lower_bound O(log(n))

  

## 3. 各种排序方法的实现
### 平方排序
- 选择排序
- 冒泡排序
- 插入排序
### 高效排序算法
- 快速排序
- 归并排序
### 线性时间排序
- 计数排序
- 桶排序
