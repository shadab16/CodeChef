#include <iostream>
#include <bitset>

std::bitset<1001117+1> r1;
std::bitset<1000110+1> r2;
std::bitset<1000053+1> r3;

static int next(int n) {

	int sum = n;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

static void init_series() {

	for (int n = 1; n <= 1001117; n = next(n)) {
		r1[n] = true;
	}
	for (int n = 3; n <= 1000110; n = next(n)) {
		r2[n] = true;
	}
	for (int n = 9; n <= 1000053; n = next(n)) {
		r3[n] = true;
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
			if (r1[n]) {
				std::cout << "1 " << n << '\n';
				break;
			}
			if (r2[n]) {
				std::cout << "3 " << n << '\n';
				break;
			}
			if (r3[n]) {
				std::cout << "9 " << n << '\n';
				break;
			}
			n = next(n);
		}
	}

	std::cout.flush();

	return 0;
}

