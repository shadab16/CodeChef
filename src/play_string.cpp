#include <algorithm>
#include <iostream>
#include <string>

bool same_sequence(const std::string& in, const std::string& str) {

	typedef std::string::const_iterator Iter;

	Iter it = str.begin();
	for (Iter inIter = in.begin(); inIter != in.end() && it != str.end(); ++inIter) {
		if (*inIter == *it) {
			++it;
		}
	}

	return it == str.end();
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases = 0;
	std::cin >> cases;

	std::string s1;
	std::string s2;
	std::string s1rev;

	while (cases--) {
		std::cin >> s1 >> s2;
		s1rev.resize(s1.size());
		reverse_copy(s1.begin(), s1.end(), s1rev.begin());

		const bool result1 = same_sequence(s1, s2);
		const bool result2 = same_sequence(s1rev, s2);

		if (result1) {
			if (result2) {
				std::cout << "3\n";
			} else {
				std::cout << "1\n";
			}
		} else if (result2) {
			std::cout << "2\n";
		} else {
			std::cout << "0\n";
		}
	}

	std::cout.flush();

	return 0;
}

