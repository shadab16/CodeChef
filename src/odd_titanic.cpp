#include <stdio.h>

int main() {

	long cases = 0;
	scanf("%ld", &cases);

	while (cases--) {

		long n = 0;
		scanf("%ld", &n);

		long shift = -1;
		for (; n; n >>= 1) {
			++shift;
		}

		printf("%ld\n", ((long) 1) << shift);
	}

	return 0;
}
