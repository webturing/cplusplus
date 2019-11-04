# coding=utf-8
'''
数组的插入排序 O(n^2)

'''
MIN,MAX=-0xffff,0x3ffff 
def insertionSort(lst):
	ordered=[MIN,MAX] #插入两个哑元，简化了插入讨论()
	for i in xrange(len(lst)):
		pos=0
		for j in xrange(0,i+1):
			if ordered[j]<lst[i]<=ordered[j+1]:#因为哑元的存在，这个式子一定满足
				pos=j+1
				break
		ordered=ordered[0:pos]+[lst[i]]+ordered[pos:]
	return ordered[1:-1]

	
if __name__=='__main__':
	lst=[12,35,99,18,76]
	print insertionSort(lst)