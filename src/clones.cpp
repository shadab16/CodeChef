#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

typedef std::map<std::string, int> map_t;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n = 0;
	int m = 0;

	while ((std::cin >> n >> m), n && m) {

		map_t map;
		std::string sequence;
		std::vector<int> frq(n);

		for (int i = 0; i < n; ++i) {
			std::cin >> sequence;
			++map[sequence];
		}

		for (map_t::const_iterator it = map.begin(); it != map.end(); ++it) {
			++frq[it->second - 1];
		}

		copy(frq.begin(), frq.end(), std::ostream_iterator<int>(std::cout, "\n"));
	}

	return 0;
}

