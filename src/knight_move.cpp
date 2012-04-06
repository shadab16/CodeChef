#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

bool valid_cell(char x, char n) {

	return x >= 'a' && x <= 'h' && n >= '1' && n <= '8';
}

bool valid_pair(const std::string& pair) {

	return pair.size() == 5 && pair[2] == '-' &&
	       valid_cell(pair[0], pair[1]) && valid_cell(pair[3], pair[4]);
}

bool valid_move(char src_x, int src_n, char dest_x, char dest_n) {

	using std::abs;
	return (abs(src_x - dest_x) == 2 && abs(src_n - dest_n) == 1) ||
	       (abs(src_x - dest_x) == 1 && abs(src_n - dest_n) == 2);
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string line;

	std::getline(std::cin, line);
	int cases = std::atoi(line.c_str());

	while (cases--) {
		std::getline(std::cin, line);
		if (!valid_pair(line)) {
			std::cout << "Error" << '\n';
		} else if (valid_move(line[0], line[1], line[3], line[4])) {
			std::cout << "Yes" << '\n';
		} else {
			std::cout << "No" << '\n';
		}
	}

	return 0;
}
