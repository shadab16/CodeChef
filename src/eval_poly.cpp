#include <iostream>

int coeff[1000];

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	for (int cases = 1; ; ++cases) {

		int degree = 0;
		std::cin >> degree;
		if (degree == -1) {
			break;
		}

		for (int i = 0, c = 0; i <= degree; ++i) {
			std::cin >> c;
			coeff[i] = c;
		}

		int k = 0;
		std::cin >> k;

		std::cout << "Case " << cases << ":\n";

		for (int i = 0, x = 0; i < k; ++i) {

			std::cin >> x;
			long long poly = coeff[degree];
			long long next_x = 1;

			for (int i = degree - 1; i >= 0; --i) {
				next_x *= x;
				poly += coeff[i] * next_x;
			}

			std::cout << poly << '\n';
		}
	}

	std::cout.flush();

	return 0;
}

