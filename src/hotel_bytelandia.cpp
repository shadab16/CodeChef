#include <iostream>
#include <algorithm>

char clash[1001] = {0};
char arrival[100] = {0};
char departure[100] = {0};

int main() {

	int cases = 0;
	std::cin >> cases;

	while (cases--) {
		int guests = 0;
		std::cin >> guests;
		for (int i = 0; i < guests; ++i) {
			std::cin >> arrival[i];
		}
		for (int i = 0; i < guests; ++i) {
			std::cin >> departure[i];
		}
		for (int i = 0; i < guests; ++i) {
			for (int j = arrival[i]; j < departure[i]; ++j) {
				++clash[j];
			}
		}
		std::cout << (int) *std::max_element(clash, clash + 1001) << '\n';
		std::fill(clash, clash + 1001, 0);
	}

	return 0;
}
