
'''
Description

图书馆占位的很厉害，只要去晚了一会就没有位置了。有些人占着位置却不来自习，这就造成了资源的浪费。现在我们的问题是一天当中有n个同学可能会来到同一个座位，假设上面有人则另外找座位，若没有人，则就可以占据此位置，直至你离开为止。为了最大化利用图书馆资源，我们要求的问题是一个位置最多能够被几个同学来用过。 
Input

多组测试数据 
第一行为n个同学 (1 <=n<=10000) 
接下来n行就是每个同学的进入图书馆的时间和离开图书馆的时间，为了简化问题，我们假设时间值为整数。


Output

输出一个座位最多被几位同学占据。
Sample Input

6
1 3
2 4
3 6
7 9
10 11
5 7
Sample Output

4
'''

import sys
 
while True:
    n, items = int(sys.stdin.readline()), []
    for case in xrange(n):
        items.append(map(int, sys.stdin.readline().strip().split(' ')))
    items, tot, cur = sorted(items, key=lambda t: t[1]), 0, 0
    for item in items:
        if item[0] >= cur:
            tot += 1
            cur = item[1]
    print tot
 