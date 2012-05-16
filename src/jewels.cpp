#include <iostream>
#include <string>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases = 0;
	std::cin >> cases;

	std::string jewels;
	std::string stones;

	while (cases--) {
		bool frq[127] = {0};
		std::cin >> jewels >> stones;
		for (std::string::const_iterator j = jewels.begin(); j != jewels.end(); ++j) {
			frq[int(*j)] = true;
		}
		int count = 0;
		for (std::string::const_iterator s = stones.begin(); s != stones.end(); ++s) {
			if (frq[int(*s)]) {
				++count;
			}
		}
		std::cout << count << '\n';
	}

	return 0;
}

