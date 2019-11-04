# Java集合框架：
## 对象类型的排序器
# java.util.Comparator<T>
# 通用的逆序器  Collections.reverseOrder();
# 自定义排序器(以字符串为例)  
```
    new Comparator<String>(){
        public int compareTo(String a,String b){
            return a.length()-b.length();//按照字符串长度非降序排列
        }
    }
```
## 泛型和集合容器
### 泛型Generic：让算法独立与数据类型（对比下C语言中的通用指针(void* ))
### 集合容器：为提升软件开发速度和质量，提供一组支持任意类型、动态长度，易于扩展的数据结构中间件
- 元素个数 size()
- 增加  add()  remove() set()
- 查询  contains()
- 迭代器访问 next() hasNext()
#### 线性容器：
- 数组表 Vector/ArrayList
- 链表   LinkedList
- 常用类 Stack/Queue/PriorityQueue
#### 树状容器：
- TreeSet
- TreeMap
#### 散列表
- HashSet
- HashMap
- HashTable
### 算法库 Collections(可以对比学习数组库Arrays)
Collections.sort()
Collections.binarySearch()
Collections.max/min

