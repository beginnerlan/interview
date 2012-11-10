#include <stdio.h>

/*
将一个数组左移k%n位，要是当年会这个方法也不至于混成这样。
其实就是reverse(a, 0, k%n-1); reverse(a, k%n, n-1); reverse(a, 0, n-1)
*/

void print_array(int *a, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void reverse(int *a, int begin, int end) {
	int b, e;
	for(b=begin, e=end; b<e; b++, e--) {
		int t = a[b];
		a[b] = a[e];
		a[e] = t;
	}
}

void shift(int *a, int n , int k) {
	int i = k % n;
	reverse(a, 0, i-1);
	reverse(a, i, n-1);
	reverse(a, 0, n-1);
}

int main(void) {
	int a[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(a)/sizeof(a[0]);
	shift(a, n, 4);
	print_array(a, n);
	return 0;
}
