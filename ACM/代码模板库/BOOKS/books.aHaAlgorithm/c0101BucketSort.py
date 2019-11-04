# coding=utf-8
'''
数组的桶排序 O(n)*O(MAX-MIN)

'''

MIN,MAX=0,100#约定每一个数据都在[0,100)之间
def bucketSort(lst):
	ans=[] #返回值
	freq=[0]*(MAX-MIN) #每一个数频度都置为0
	for ele in lst:
		freq[ele]+=1 #统计频率
	for idx in xrange(MIN,MAX): #还原
		for k in xrange(freq[idx]):
			ans.append(idx),
	return ans

if __name__=='__main__':
	lst=[2,8,5,3,5]
	print bucketSort(lst)