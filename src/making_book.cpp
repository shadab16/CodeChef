#include <iostream>

int main() {

	int a, b;

	for (int cases = 1; ; ++cases) {
		std::cin >> a;
		if (a == 0) {
			break;
		}
		std::cin >> b;
		if (a > b) {
			int x = a;
			a = b;
			b = x;
		}
		int digits[10] = {0};
		for (int n = a; n <= b; ++n) {
			for (int n_ = n; n_; n_ /= 10) {
				++digits[n_ % 10];
			}
		}
		std::cout << "Case " << cases << ":";
		for (int i = 0; i < 10; ++i) {
			std::cout << " " << i << ":" << digits[i];
		}
		std::cout << '\n';
	}

	std::cout.flush();

	return 0;
}

