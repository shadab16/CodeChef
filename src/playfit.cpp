#include <iostream>

char line[100000 * 7];
char* buf = line;

void get() {
	std::cin.getline(line, 700000);
	buf = line;
}

int next() {
	while (*buf < '0') {
		++buf;
	}
	int n = 0;
	while (*buf >= '0') {
		n = (n * 10) + (*buf - '0');
		++buf;
	}
	return n;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	get();
	int cases = next();

	while (cases--) {
		get();
		int limit = next();

		get();
		int max = next();
		int min = max;
		int diff = 0;
		for (int i = 1; i < limit; ++i) {
			int n = next();
			if (n < min) {
				min = n;
				max = n;
			} else if (n > max) {
				max = n;
			}
			if (max - min > diff) {
				diff = max - min;
			}
		}

		if (diff) {
			std::cout << diff << '\n';
		} else {
			std::cout << "UNFIT\n";
		}
	}

	return 0;
}

