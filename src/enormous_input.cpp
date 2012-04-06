#include <iostream>

int main() {

	int count = 0;
	int limit = 0;
	int k = 0;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> limit >> k;

	while (limit--) {
		int n = 0;
		std::cin >> n;
		if (n % k == 0) {
			++count;
		}
	}

	std::cout << count << std::endl;

	return 0;
}
