#include <memory.h>
#include <stdio.h>

#define MAX 1000001
/*
选出2到1000000之间的素数，其实就是去掉2的倍数，3个倍数...最后剩下的就是了
*/
int main(void) {
	int a[MAX];
	memset(a, 0, sizeof(a));
	int i;
	for(i=2; i<MAX; i++)
		if(i == 2 || i%2 != 0)
			a[i] = i;
		else
			a[i] = 0;

	int j;
	for(i=2; i*i<=MAX; i++) {//这里应该从i=3开始比较好，2的倍数上面就已经干掉了
		for(j=i+i; j<MAX; j+=i) {
			if(a[i] != 0)
				a[j]=0;
		}
	}

	for(i=2; i<MAX; i++) {
		if(a[i] != 0)
			printf("%7d\n", a[i]);
	}
	return 0;
}
