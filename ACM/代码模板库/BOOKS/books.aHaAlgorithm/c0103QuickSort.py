# coding=utf-8
'''
数组的快速排序 O(NlogN)

'''

def quickSort(lst):
	if len(lst)<=1:
		return lst
	mid=[x for x in lst if x==lst[0]]
	left=[x for x in lst if x<lst[0]]
	right=[x for x in lst if x>lst[0]]
	return quickSort(left)+mid+quickSort(right)

	
if __name__=='__main__':
	lst=[6,1,7,2,9,3,4,5,10,8]
	print quickSort(lst)