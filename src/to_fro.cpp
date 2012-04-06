#include <iostream>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int col = 0;
	std::string line;
	line.reserve(200);

	while ((std::cin >> col), col) {

		std::cin >> line;
		const int row = line.size() / col;

		for (int offset = 1; offset <= col; ++offset) {
			for (int i = 0; i < row; ++i) {
				if (i % 2 == 0) {
					std::cout << line[(i * col) + (offset - 1)];
				} else {
					std::cout << line[(i * col) + (col - offset)];
				}
			}
		}

		std::cout << '\n';

	}

	std::cout.flush();

	return 0;
}

