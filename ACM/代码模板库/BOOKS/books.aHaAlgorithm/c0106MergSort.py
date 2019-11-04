# coding=utf-8
'''
数组的归并排序 O(nLogn)

'''
MAX=0x3ffff  #哑元
def mergeSort(lst):
	if len(lst)<=1:
		return lst
	half=len(lst)/2
	left=mergeSort(lst[0:half])+[MAX]
	right=mergeSort(lst[half:])+[MAX]
	res,i,j=[],0,0
	while len(res)<len(lst) :
		if left[i]<=right[j]:
			res+=[left[i]]
			i+=1
		else:
			res+=[right[j]]
			j+=1
	return res


	
if __name__=='__main__':
	lst=[12,35,99,18,76]
	print mergeSort(lst)