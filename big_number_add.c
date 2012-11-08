#include <string.h>
#include <stdio.h>
#define N 1000
/*
大数加法，将两个加数放在两个数组a和b中，然后对应位相加放在数组c中，然后才处理进位问题
代码通俗易懂。	
*/
int main(void)
{
	char a[N], b[N];
	int c[N+1];
	int t;
	scanf("%d", &t);
	int loops;
	for(loops = 1; loops<=t; loops++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		scanf("%s %s", a, b);
		int la = strlen(a);
		int lb = strlen(b);
		int length = (la > lb ? la : lb)+1;
		int i, j, k=0;
		for(i=la-1, j=lb-1; i>=0&&j>=0; i--, j--) {
			c[k++] = a[i]-'0'+b[j]-'0';
		}
		while(i>=0)
			c[k++] = a[i--]-'0';
		while(j>=0)
			c[k++] = b[j--]-'0';
		int carrier = 0;
		for(i=0; i<k; i++) {
			c[i] += carrier;
			if(c[i] > 9) {
				c[i] %= 10;
				carrier = 1;
			}else 
				carrier = 0;
		}
		printf("Case %d:\n", loops);
		printf("%s + %s = ", a, b);
		if(carrier == 1)
			printf("1");
		for(i=k-1; i>=0; i--)
			printf("%d", c[i]);
		printf("%s", loops==t ? "\n" : "\n\n");
	}
	return 0;
}
