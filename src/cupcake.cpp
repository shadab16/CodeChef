#include <iostream>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases;
	std::cin >> cases;

	while (cases--) {
		int n;
		std::cin >> n;
		int mindiff = n;
		for (int i = 1; i * i <= n; ++i) {
			const int width = n / i;
			if (width * i != n) {
				continue;
			}
			const int diff = width - i;
			if (diff < mindiff) {
				mindiff = diff;
			}
		}
		std::cout << mindiff << '\n';
	}

	return 0;
}

