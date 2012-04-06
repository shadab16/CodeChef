#include <iostream>

/* Reference: http://mathworld.wolfram.com/Factorial.html */
long Z(const long num) {
	long count = 0;
	for (long n = 5; n <= num; n *= 5) {
		count += num / n;
	}

	return count;
}

int main() {

	int limit = 0;
	std::cin >> limit;

	while (limit-- > 0) {
		long n = 0;
		std::cin >> n;
		std::cout << Z(n) << '\n';
	}

	return 0;
}
