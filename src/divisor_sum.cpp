#include <iostream>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases = 0;
	long num = 0;
	std::cin >> cases;

	while (cases--) {
		std::cin >> num;
		long sum = 1;
		int i;
		for (i = 2; i * i < num; ++i) {
			if (num % i == 0) {
				sum += i + num / i;
			}
		}
		if (i * i == num) {
			sum += i;
		}
		std::cout << sum << '\n';
	}

	std::cout.flush();

	return 0;
}

