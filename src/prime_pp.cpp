#include <bitset>
#include <iostream>
#include <vector>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::bitset<1000000> sieve;
	sieve[0] = 1;
	sieve[1] = 1;

	for (size_t i = 2; i < 1000; ++i) {
		if (sieve[i]) {
			continue;
		}
		for (size_t j = i; i * j < 1000000; ++j) {
			sieve[i * j] = 1;
		}
	}

	std::vector<long long> accumulate(100001);
	long long sum = 0;

	for (size_t i = 2; i <= 1000000; ++i) {
		if (i % 10 == 0) {
			accumulate[i / 10] = sum;
		} else if (!sieve[i]) {
			sum += i;
		}
	}

	int cases;
	std::cin >> cases;

	while (cases--) {
		int n;
		std::cin >> n;
		long long sum = accumulate[n / 10];
		for (int i = (n / 10) * 10; i < n; ++i) {
			if (!sieve[i]) {
				sum += i;
			}
		}
		std::cout << sum << '\n';
	}

	std::cout.flush();

	return 0;
}

