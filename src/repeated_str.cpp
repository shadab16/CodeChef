#include <iostream>
#include <string>

int find(const std::string& line, size_t len) {

	int maxcount = 0;

	for (size_t i = 0; i <= line.size() - len; ++i) {
		std::string str = line.substr(i, len);
		int count = 1;
		for (size_t j = i + 1; j <= line.size() - len; ++j) {
			if (line.compare(j, len, str) == 0) {
				++count;
			}
		}
		if (count > maxcount) {
			maxcount = count;
		}
	}

	return maxcount;
}

void find(const std::string& line, size_t low, size_t high) {

	int maxtimes = 0;
	int maxlen = 0;

	for (size_t len = low; len <= high; ++len) {
		const int times = find(line, len);
		if (times >= maxtimes) {
			maxtimes = times;
			maxlen = len;
		}
	}

	std::cout << maxtimes << " " << maxlen << "\n";
}

int main() {

	size_t low = 0;
	size_t high = 0;
	std::string line;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	while ((std::cin >> low >> high), low && high) {
		std::cin >> line;
		find(line, low, high);
	}
}
