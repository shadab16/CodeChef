#include <iostream>
#include <map>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int tests = 0;
	std::cin >> tests;

	std::map<int, int> nums;

	while (tests--) {

		int limit = 0;
		std::cin >> limit;

		while (limit--) {
			int n = 0;
			std::cin >> n;
			++nums[n];
		}

		std::map<int, int>::const_iterator max = nums.begin();

		for (std::map<int, int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
			if (it->second > max->second) {
				max = it;
			}
		}

		std::cout << max->first << ' ' << max->second << '\n';

		nums.clear();
	}
}

