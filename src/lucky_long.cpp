#include <iostream>
#include <string>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases = 0;
	std::cin >> cases;
	std::string num;
	num.reserve(100000);

	while (cases--) {
		std::cin >> num;
		int diff = 0;
		for (std::string::const_iterator it = num.begin(); it != num.end(); ++it) {
			if (*it >= '0' && *it <= '9' && *it != '4' && *it != '7') {
				++diff;
			}
		}
		std::cout << diff << '\n';
	}

	std::cout.flush();

	return 0;
}

