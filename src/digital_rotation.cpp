#include <algorithm>
#include <iostream>
#include <cmath>

int main() {

	int cases = 0;
	std::cin >> cases;

	while (cases--) {
		long n = 0;
		long max = 0;

		std::cin >> n;

		const int digits = std::log10(n);

		long n_ = n;
		for (int i = 0; i <= digits; ++i) {
			// left
			const long p = std::pow(10, std::log10(n_));
			n_ = ((n_ % p) * 10) + (n_ / p);
			max = std::max(max, n_);
		}
		n_ = n;
		for (int i = 0; i <= digits; ++i) {
			// right
			const long p = std::pow(10, std::log10(n_));
			n_ = (n_ / 10) + (p * (n_ % 10));
			max = std::max(max, n_);
		}

		std::cout << max << '\n';
	}

	return 0;
}
