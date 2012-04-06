#include <iostream>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases = 0;
	std::cin >> cases;

	char str[100 * 101];

	while (cases--) {

		int r, c;
		std::cin >> r >> c;
		std::cin.read(str, r * (c + 1));

		for (int src = 0, dest = 0; src < r * (c + 1); ++src) {
			if (str[src] >= 'A') {
				str[dest++] = str[src] | 32;
			}
		}

		bool found = false;

		for (int i = 0; i < r * c; ++i) {
			if (str[i] != 's') {
				continue;
			}
			if (i % c < c - 4 && str[i+1] == 'p' && str[i+2] == 'o' && str[i+3] == 'o' && str[i+4] == 'n') {
				found = true;
				break;
			}
			if (i < (r - 4) * c && str[i+c] == 'p' && str[i+2*c] == 'o' && str[i+3*c] == 'o' && str[i+4*c] == 'n') {
				found = true;
				break;
			}
		}
		std::cout << (found ? "There is a spoon!\n" : "There is indeed no spoon!\n");
	}

	std::cout.flush();

	return 0;
}

