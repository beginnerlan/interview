#include <memory.h>
#include <stdio.h>
#define MAX 10000
/*
最大子序列和。如果全是负数，输出0，第一个元素和最后一个元素，否则输出最大子序列
和的值，最大子序列的第一个元素与最后一个元素。
分析：设置一个标记flag表示是否有大于等于0的元素，这个容易解决。假设最大子序列和，子序列开始，结束分别用max，start，end表示，用sum表示从上一次sum=0到当前元素的一个子序列和，position标记和为sum的子序列的起始下标，如果当前元素使得sum<0了，即sum+a[i]<0，那么这个子序列肯定不会是所要求的最大子序列的一部分，所以丢弃，且让sum=0，且position=i+1，即从当前元素的下一个开始；要是sum+a[i]>max，即加上a[i]后的子序列的和比当前找到的最大子序列和还大，则更新max，且start=position，end=i。
*/
int main(void) 
{
	int n, num[MAX];
	while(scanf("%d", &n), n) {
		int i, flag = 0;
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++) {
			scanf("%d", &num[i]);
			if(num[i] >= 0)
				flag = 1;
		}
		if(flag==0)  {
			printf("0 %d %d\n", num[0], num[n-1]);
			continue;
		}
		int start, end, position, max, sum;
		start = end = position = 0;
		max = sum = 0;
		for(i=0; i<n; i++) {
			sum += num[i];
			if(sum > max) {
				max = sum;
				start = position;
				end = i;
			}
			if(sum < 0) {
				sum = 0;
				position = i+1;
			}
		}
		printf("%d %d %d\n", max, num[start], num[end]);
	}
}
