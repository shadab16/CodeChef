#include <cstdio>
#include <cstdlib>

long nums[1000001] = {0};

int main(void) {

	long cases = 0;
	std::scanf("%ld", &cases);

	while (cases--) {
		unsigned long n = 0;
		std::scanf("%lu", &n);
		++nums[n];
	}

	for (long i = 0; i <= 1000000; ++i) {
		while (nums[i]--) {
			std::printf("%ld\n", i);
		}
	}

	return 0;
}
