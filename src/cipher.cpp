#include <iostream>
#include <string>

typedef std::string::const_iterator Iter;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string str;
	std::string filter;
	unsigned int frq[26] = {0};

	std::cin >> str >> filter;

	for (Iter it = str.begin(); it != str.end(); ++it) {
		++frq[*it - 'a'];
	}

	for (Iter it = filter.begin(); it != filter.end(); ++it) {
		frq[*it - 'a'] = 0;
	}

	for (size_t i = 0; i < 26; ++i) {
		if (frq[i]) {
			std::cout << char(i + 'a') << frq[i];
		}
	}

	std::cout << std::endl;

	return 0;
}

