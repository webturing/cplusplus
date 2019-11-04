# coding=utf-8
'''
数组的选择排序 O(n^2)

'''

def selectionSort(lst):
	for i in xrange(len(lst)):
		minIndex=lst[i:].index(min(lst[i:]))+i ##容易犯错，查找的是lst[i:]的坐标，相对于lst应该+i
		lst[i],lst[minIndex]=lst[minIndex],lst[i]
	return lst

	
if __name__=='__main__':
	lst=[12,35,99,18,76]
	print selectionSort(lst)