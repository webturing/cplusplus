# ACM算法基础: 字符串、基础数据结构和算法、STL

## 字符串

### 字符 `#include <cctype>`
- tolower/toupper/
  - '0'-'9'   '0'=48
  - 'a'-'z'    'a'=97
  - 'A'-'Z'   'A'=65
- isupper/islower/isalpha/isdigit/isxdigit 

### 字符串 C风格`#include<cstring>`

C字符串 以第一个'\0'=0=NULL 为自然终止符的字符序列

- strlen  ` int strlen(char*s){ char *p=s;while(*p)++p;return p-s;}`//O(n)

  ```for(int i=0;i<strlen(s);i++)cout<<s[i]<<endl;```//O(n^2)

  ``` for(int i=0,n=strlen(n);i<n;i++)cout<<s[i]<<endl;```//O(n)

- 串拷贝/连接/字典比较:strcat/strcpy

- 类型转化 sscanf/sprintf

- 串查找 strstr //KMP

### 字符串II C++ string `#include<string>`

C++字符串  vector<char>  //长度和内容可以改变的动态的字符数组

- size/length
- reverse
- find
- istringstream/ostringstream

###基本应用   
- 排序 sort/qsort
- 翻转 reverse
- 统计查找  map

## STL 数据结构：
### 元组 pair 
- first/second
- 内置了字典序和equal
- make_pair

### 线性  
- vector
- list
- stack
- queue

### 树 
- set/multiset
- priority_queue
- map

## STL算法 `#include<algorithm>`
### 排序
- 默认非降序
- 增序
- 自定义比较规则

### 查找/统计
#### 线性查找 /统计
- find
- count


### 二分查找：
- binary_search
- lower_bound
- upper_bound

### 其他
- 变换 transform
- 去重 unique
