# 第二讲：数组和字符串
## 数组：
### 定义和使用：
* 利用常量定义 int[] a={1,2,3,4}
** 动态申请   
- int[] a=new int[10];//分配的长度为10 初值全部为0
- int[] a=new int[]{1,2,3,4};//创造一个长度为和内容和a一样的副本
- int[] a=(int[])b.clone();//同上
- int[] a=b;//数组a,b指向同一个内存
### 数组管理：
* 数组长度：a.length
* 随机访问：a[index]  index 必须在[0,a.length-1]之间，否则抛出ArrayIndexOutOfBoundary异常
* 字符串方法： Arrays.toString(arr)
### 循环访问：
- fori
``` for(int i=0;i<a.length;i++){//DOSOMETHING} ``` 
                                               //索引模式 仅限于数组
- foreach 
 ```for(int i:a){//DOSOMETHING}```
                                               //迭代器模式，支持所有数组，集合，容器
### 数组算法：java.util.Arrays
- 数组填充 Arrays.fill/System.arrayCopy
- 数组排序 Arrays.sort
- 有序数组的二分查找:Arrays.binarySearch
                                                        
```$xslt
import java.util.Arrays;

public class ArraysDemo {
    public static void main(String[] args) {
        int[] a = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
        System.out.println(a[0]);
        System.out.println(a.length);//10
        System.out.println(a[a.length - 1]);
        for (int i : a) { //foreach
            System.out.println(i);
        }
        Arrays.sort(a);
        for (int i = 0; i < a.length; i++) {//forindex
            System.out.print(a[i]);
        }
    }
}
```
## 字符串
### String不可变字符串 Immutable(类似于数组)
- 长度  s.length()
- 索引访问/查找  s.charAt(index)/s.indexOf(char)
- 子串  subtring(fromIndex)/substring(fromIndex,endIndex)/indexOf/contains
- 转化为字符数组  toCharArray
- 格式化方法 String.format
### String字符串运算
- 字符串连接+   a+b 如果只要有一个是String 结果就是新的字符串  
- s="a"+s   意义是创造一个新的字符串内容是"a"和s原来的内容的拼接，s抛弃原来的引用，指向新的串
- 字符串大小写相关  toUpperCase/toLowerCase
- 去除首尾空格  trim
- 字符串切割为字符串数组(正则表达式)   split(string,regex)
###可变字符串 StringBuffer/StringBuilder
