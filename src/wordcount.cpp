#include <iostream>
#include <string>
#include <cmath>

const int mod = 1e9 + 7;

// log2 (n!)
double log_fac[501] = {0.0};

void init() {

	for (int i = 1; i <= 500; ++i) {
		log_fac[i] = log_fac[i - 1] + (std::log(i) / std::log(2.0));
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();

	int tests = 0;
	std::cin >> tests;

	while (tests--) {
		std::string word;
		std::cin >> word;

		unsigned char frequency[58] = {0};

		for (std::string::const_iterator c = word.begin(); c != word.end(); ++c) {
			++frequency[*c - 65];
		}

		double count = log_fac[word.size()];

		for (size_t i = 0; i < 58; ++i) {
			if (frequency[i] > 1) {
				count -= log_fac[frequency[i]];
			}
		}

		double fraction = std::modf(count, &count);
		long result = 1;

		for (int i = count; i > 0; --i) {
			result = (result * 2) % mod;
		}

		result = long(std::pow(2.0, fraction) * result) % mod;

		std::cout << result << '\n';
	}

	return 0;
}

