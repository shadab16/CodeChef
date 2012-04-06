#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> r1;
std::vector<int> r2;
std::vector<int> r3;

static int next(int n) {

	int sum = n;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

static void init_series() {

	r1.reserve(39098);
	for (int n = 1; n <= 1001117; n = next(n)) {
		r1.push_back(n);
	}
	r2.reserve(38277);
	for (int n = 3; n <= 1000110; n = next(n)) {
		r2.push_back(n);
	}
	r3.reserve(38958);
	for (int n = 9; n <= 1000053; n = next(n)) {
		r3.push_back(n);
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init_series();

	int cases = 0;
	std::cin >> cases;

	while (cases--) {

		int n;
		std::cin >> n;

		while (true) {
			if (std::binary_search(r1.begin(), r1.end(), n)) {
				std::cout << "1 " << n << '\n';
				break;
			}
			if (std::binary_search(r2.begin(), r2.end(), n)) {
				std::cout << "3 " << n << '\n';
				break;
			}
			if (std::binary_search(r3.begin(), r3.end(), n)) {
				std::cout << "9 " << n << '\n';
				break;
			}
			n = next(n);
		}
	}

	std::cout.flush();

	return 0;
}

