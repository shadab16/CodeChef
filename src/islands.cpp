#include <iostream>
#include <bitset>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::bitset<40000> map;
	int cases = 0;
	int row = 0;
	int col = 0;

	std::cin >> cases;

	while (cases--) {

		int count = 0;
		std::cin >> row >> col;

		for (int i = 0; i < row * col;) {
			switch (std::cin.get()) {
			case '#':
				map[i] = true;

				/* check if there's any adjacent land */
				/* if there is, don't increment counter */
				if (!(map[i-1] || map[i-col] || map[i-col+1] || map[i-col-1])) {
					++count;
				}

				/* no break */
			case '.':
				++i;
			}
		}

		std::cout << count << std::endl;
	}

	return 0;
}

