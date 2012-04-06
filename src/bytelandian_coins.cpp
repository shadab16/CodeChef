#include <iostream>

unsigned long cache[10000];

unsigned long exchange(const unsigned long n) {
	if ((n / 2) + (n / 3) + (n / 4) <= n) {
		return n;
	}
	if (n < 10000 && cache[n]) {
		return cache[n];
	}
	const unsigned long forex = exchange(n / 2) + exchange(n / 3) + exchange(n / 4);
	if (n < 10000) {
		cache[n] = forex;
	}
	return forex;
}

int main() {

	unsigned long value = 0;
	while (std::cin >> value) {
		std::cout << exchange(value) << std::endl;
	}

	return 0;
}
