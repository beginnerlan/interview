#include <stdio.h>
#include <assert.h>

void swap(char *a, int k, int i) {
	char t = a[k];
	a[k] = a[i];
	a[i] = t;
} 

/*
求n个不同的字母的所有排列，不知道如果有重复的字母要怎么搞？
假设这些字母为S = {s1, s2, s3,..., sn}，Si = S - {si}，perm(S)为
所求，那么perm(S) = (s1)perm(S1)+(s2)perm(S2)+...+(sn)perm(Sn)，
其中"+"表示并操作，其实就是s1和si（i=1, 2, 3, ..., n）交换，然后
求后面n-1个字符的所有排列。实现：perm(s, k, m)表示s[0...k-1]为前缀，
s[k...m]的所有全排列为后缀的集合，递归地求。当k==m时，输出一个排列
*/
void perm(char *a, int k, int m) {
	assert(k <= m);
	int i;
	if(k == m) {
		for(i=0; i<=m; i++) {
			printf("%c", a[i]);
		}
		printf("\n");
	} else {
		for(i=k; i<=m; i++) { 
			swap(a, k, i);
			perm(a, k+1, m);
			swap(a, k, i);
		}
	}
}

int main(void) {
	char a[] = {'1', '2', '3'};
	int n = sizeof(a)/sizeof(a[0]);
	perm(a, 0, n-1);
	return 0;
}
