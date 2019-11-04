# coding=utf-8
'''
数组的冒泡排序 O(n^2)

'''


def bubbleSort(lst):
	for i in xrange(len(lst)):
		for j in xrange(len(lst)-i-1):
			if lst[j]>lst[j+1]:
				lst[j],lst[j+1]=lst[j+1],lst[j]
	return lst

	
if __name__=='__main__':
	lst=[12,35,99,18,76]
	print bubbleSort(lst)