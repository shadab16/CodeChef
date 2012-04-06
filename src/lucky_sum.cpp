#include <algorithm>
#include <iostream>
#include <vector>

bool is_lucky(int n) {

	while (n) {
		const int digit = n % 10;
		if (digit != 4 && digit != 7) {
			return false;
		}
		n /= 10;
	}

	return true;
}

int sum(const std::vector<int>& nums) {

	int sum = 0;

	for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {

		int m = sum;
		int n = *it;
		int multiplier = 1;
		sum = 0;

		while (m || n) {

			sum += std::max(m % 10, n % 10) * multiplier;
			m /= 10;
			n /= 10;
			multiplier *= 10;
		}
	}

	return sum;
}

unsigned long long count_seq(const std::vector<int>& nums) {

	typedef unsigned long long uint64;

	const uint64 limit = 1ULL << nums.size();
	uint64 count = 0;

	for (uint64 comb = 1; comb < limit; ++comb) {

		std::vector<int> seq;

		for (uint64 c = 0; c < nums.size(); ++c) {
			if (comb & (1ULL << c)) {
				seq.push_back(nums[c]);
			}
		}

		if (is_lucky(sum(seq))) {
			++count;
		}
	}

	return count;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int limit = 0;
	std::cin >> limit;
	std::vector<int> nums;
	nums.reserve(50);

	while (limit--) {

		int count = 0;
		std::cin >> count;

		while (count--) {

			int n = 0;
			std::cin >> n;
			nums.push_back(n);
		}

		std::cout << count_seq(nums) << '\n';

		nums.clear();
	}

	return 0;
}

