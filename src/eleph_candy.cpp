#include <iostream>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases;
	std::cin >> cases;

	const char* result[2] = {"No\n", "Yes\n"};

	while (cases--) {
		int eleph;
		int candies;
		std::cin >> eleph >> candies;
		while (eleph--) {
			int min;
			std::cin >> min;
			candies -= min;
		}
		std::cout << result[candies >= 0];
	}

	return 0;
}

